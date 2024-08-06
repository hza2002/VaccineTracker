#include <stdio.h>
#include <string.h>

#include "main/doctor.h"
#include "shared/data.h"

int doctor_num = 0;  // 医生数量

// 读取 DoctorPath 中的数据到结构体，成功返回0，失败-1
int ReadDoctor() {
    FILE *fp;
    // 打开数据文件
    if ((fp = fopen(DoctorPath, "r")) == NULL) {
        printf("打开文件%s错误\n", DoctorPath);
        return -1;
    }
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
    while (!feof(fp)) {
        fscanf(fp, "%lld,%[^,],%s", &doctors[doctor_num].id,
               doctors[doctor_num].name, doctors[doctor_num].hospital);
        doctor_num++;
    }  // 逐行获取结构体内容
    fclose(fp);
    return 0;
}

// 将结构体写入文件，成功返回0，失败-1
int WriteDoctor() {
    FILE *fp;
    // 打开数据文件
    if ((fp = fopen(DoctorPath, "w")) == NULL) {
        printf("打开文件%s错误\n", DoctorPath);
        return -1;
    }
    fprintf(fp, "id,name,hospital\n");  // 写入第一行（标题）的内容
    for (int i = 0; i < doctor_num; ++i) {
        fprintf(fp, "%lld,%s,%s\n", doctors[i].id, doctors[i].name,
                doctors[i].hospital);
    }  // 逐行写入结构体内容
    fclose(fp);
    return 0;
}

// 查找医生信息
int SearchDoctor(long long id) {
    for (int i = 0; i < doctor_num; ++i) {
        if (doctors[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 增加医生信息，成功返回0，失败-1
int AddDoctor(Doctor new_doctor) {
    int index = SearchDoctor(new_doctor.id);
    if (index != -1) {
        printf("存在编号相同的医生\n");
        return -1;
    } else {
        doctors[doctor_num] = new_doctor;
        doctor_num++;
        WriteDoctor();
    }
    return 0;
}

// 删除医生信息，成功返回0，失败-1
int DeleteDoctor(long long id) {
    int index = SearchDoctor(id);
    if (index == -1) {
        return -1;
    } else {
        FILE *fp;  // 打开数据文件
        if ((fp = fopen(DoctorPath, "w")) == NULL) {
            printf("打开文件%s错误\n", DoctorPath);
            return -1;
        }
        fprintf(fp, "id,name,hospital\n");  // 写入第一行（标题）的内容
        for (int i = 0; i < doctor_num; ++i) {
            if (i == index) continue;
            fprintf(fp, "%lld,%s,%s\n", doctors[i].id, doctors[i].name,
                    doctors[i].hospital);
        }  // 逐行写入结构体内容
        fclose(fp);
        doctor_num = 0;
        ReadDoctor();
    }
    return 0;
}

// 修改医生信息
void EditDoctor() {
    printf("请输入需要修改的医生ID: ");
    long long id;
    scanf("%lld", &id);
    int index = SearchDoctor(id);
    if (index == -1) {
        printf("不存在该医生\n");
    } else {
        printf("需要修改的医生信息\n");
        printf("ID:%lld 姓名:%s 所属医院:%s\n", doctors[index].id,
               doctors[index].name, doctors[index].hospital);
        printf("请输入修改后的的医生姓名: ");
        scanf("%s", doctors[index].name);
        printf("请输入修改后的医生所属医院: ");
        scanf("%s", doctors[index].hospital);
        WriteDoctor();
        printf("修改成功\n");
    }
}