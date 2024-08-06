#include <stdio.h>
#include <string.h>

#include "main/doctor.h"
#include "main/person.h"
#include "main/vaccine.h"
#include "main/record.h"
#include "shared/data.h"

int record_num = 0;  // 接种信息数量

// 读取 RecordPath 中的数据到结构体，成功返回0，失败-1
int ReadRecord() {
    FILE *fp;
    // 打开数据文件
    if ((fp = fopen(RecordPath, "r")) == NULL) {
        printf("打开文件%s错误\n", RecordPath);
        return -1;
    }
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
    while (!feof(fp)) {
        fscanf(fp, "%lld,%[^,],%lld,%lld,%d,%d,%d\n", &records[record_num].id,
               records[record_num].person_id, &records[record_num].doctor_id,
               &records[record_num].vaccine_id, &records[record_num].year,
               &records[record_num].month, &records[record_num].day);
        record_num++;
    }  // 逐行获取结构体内容
    fclose(fp);
    return 0;
}

// 将结构体写入文件，成功返回0，失败-1
int WriteRecord() {
    FILE *fp;
    // 打开数据文件
    if ((fp = fopen(RecordPath, "w")) == NULL) {
        printf("打开文件%s错误\n", RecordPath);
        return -1;
    }
    fprintf(fp, "id,person_id,doctor_id,vaccine_id,year,month,day\n");
    for (int i = 0; i < record_num; ++i) {
        fprintf(fp, "%lld,%s,%lld,%lld,%d,%d,%d\n", records[i].id,
                records[i].person_id, records[i].doctor_id, records[i].vaccine_id,
                records[i].year, records[i].month, records[i].day);
    }  // 逐行写入结构体内容
    fclose(fp);
    return 0;
}

// 查找接种信息
int SearchRecord(long long id) {
    for (int i = 0; i < record_num; ++i) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 增加接种信息，成功返回0，失败-1
int AddRecord(Record new_record) {
    int flag = 0;
    if (SearchPerson(new_record.person_id) == -1) {
        printf("接种人未注册\n");
        flag = 1;
    }
    if (SearchDoctor(new_record.doctor_id) == -1) {
        printf("医生未注册\n");
        flag = 1;
    }
    if (SearchVaccine(new_record.vaccine_id) == -1) {
        printf("疫苗未注册\n");
        flag = 1;
    }
    if (flag == 0) {
        records[record_num] = new_record;
        record_num++;
        WriteRecord();
    }
    return flag;
}

// 删除接种信息，成功返回0，失败-1
int DeleteRecord(long long id) {
    int index = SearchRecord(id);
    if (index == -1) {
        return -1;
    } else {
        FILE *fp;  // 打开数据文件
        if ((fp = fopen(RecordPath, "w")) == NULL) {
            printf("打开文件%s错误\n", RecordPath);
            return -1;
        }
        fprintf(fp, "id,person_id,doctor_id,vaccine_id,year,month,day\n");
        for (int i = 0; i < record_num; ++i) {
            if (i == index) continue;
            fprintf(fp, "%lld,%s,%lld,%lld,%d,%d,%d\n", records[i].id,
                    records[i].person_id, records[i].doctor_id, records[i].vaccine_id,
                    records[i].year, records[i].month, records[i].day);
        }  // 逐行写入结构体内容
        fclose(fp);
        record_num = 0;
        ReadRecord();
    }
    return 0;
}