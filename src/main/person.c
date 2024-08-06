#include <stdio.h>
#include <string.h>

#include "main/person.h"
#include "shared/data.h"

int person_num = 0;  // 接种者数量

// 读取 PersonPath 中的数据到结构体，成功返回0，失败-1
int ReadPerson() {
    FILE *fp;
    // 打开数据文件
    if ((fp = fopen(PersonPath, "r")) == NULL) {
        printf("打开文件%s错误\n", PersonPath);
        return -1;
    }
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
    while (!feof(fp)) {
        fscanf(fp, "%[^,],%[^,],%lld\n", persons[person_num].id,
               persons[person_num].name, &persons[person_num].phone);
        person_num++;
    }  // 逐行获取结
    fclose(fp);
    return 0;
}

// 将结构体写入文件，成功返回0，失败-1
int WritePerson() {
    FILE *fp;
    // 打开数据文件
    if ((fp = fopen(PersonPath, "w")) == NULL) {
        printf("打开文件%s错误\n", PersonPath);
        return -1;
    }
    fprintf(fp, "id,name,phone\n");  // 写入第一行（标题）的内容
    for (int i = 0; i < person_num; ++i) {
        fprintf(fp, "%s,%s,%lld\n", persons[i].id, persons[i].name,
                persons[i].phone);
    }  // 逐行写入结构体内容
    fclose(fp);
    return 0;
}

// 查找接种者信息
int SearchPerson(char id[]) {
    for (int i = 0; i < person_num; ++i) {
        if (strcmp(persons[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
};

// 增加接种者信息，成功返回0，失败-1
int AddPerson(Person new_person) {
    int index = SearchPerson(new_person.id);
    if (index != -1) {
        printf("存在编号相同的接种者\n");
        return -1;
    } else {
        persons[person_num] = new_person;
        person_num++;
        WritePerson();
    }
    return 0;
}

// 删除接种者信息，成功返回0，失败-1
int DeletePerson(char id[]) {
    int index = SearchPerson(id);
    if (index == -1) {
        return -1;
    } else {
        FILE *fp;  // 打开数据文件
        if ((fp = fopen(PersonPath, "w")) == NULL) {
            printf("打开文件%s错误\n", PersonPath);
            return -1;
        }
        fprintf(fp, "id,name,phone\n");  // 写入第一行（标题）的内容
        for (int i = 0; i < person_num; ++i) {
            if (i == index) continue;
            fprintf(fp, "%s,%s,%lld\n", persons[i].id, persons[i].name,
                    persons[i].phone);
        }  // 逐行写入结构体内容
        fclose(fp);
        person_num = 0;
        ReadPerson();
    }
    return 0;
}

// 修改接种者信息
void EditPerson() {
    printf("请输入需要修改的接种者的身份证号: ");
    char id[20];
    scanf("%s", id);
    int index = SearchPerson(id);
    if (index == -1) {
        printf("不存在该接种者\n");
    } else {
        printf("需要修改的接种者信息\n");
        printf("身份证号:%s 姓名：%s 联系方式:%lld\n", persons[index].id,
               persons[index].name, persons[index].phone);
        printf("请输入修改后的的接种者姓名: ");
        scanf("%s", persons[index].name);
        printf("请输入修改后的接种者联系电话: ");
        scanf("%lld", &persons[index].phone);
        WritePerson();
        printf("修改成功\n");
    }
}