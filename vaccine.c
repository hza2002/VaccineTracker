#include "vaccine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* VaccinePath = "data/vaccine.csv";
char vaccine_type[VACCINENUM][30] = {
    "北京生物新冠疫苗", "科兴中维新冠疫苗", "武汉生物新冠疫苗",
    "康希诺新冠疫苗",   "智飞新冠疫苗",     "康泰新冠疫苗",
    "医科生物新冠疫苗",
};
int vaccine_num = 0;  // 疫苗数量

// 读取 VaccinePath 中的数据到结构体，成功返回0，失败-1
int ReadVaccine() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(VaccinePath, "r")) == NULL) {
    printf("打开文件%s错误\n", VaccinePath);
    return -1;
  }
  char buffer[1024];
  fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
  while (!feof(fp)) {
    fscanf(fp, "%lld,%d\n", &vaccines[vaccine_num].id,
           &vaccines[vaccine_num].type);
    vaccine_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}

// 将结构体写入文件，成功返回0，失败-1
int WriteVaccine() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(VaccinePath, "w")) == NULL) {
    printf("打开文件%s错误\n", VaccinePath);
    return -1;
  }
  fprintf(fp, "id,type,\n");  // 写入第一行（标题）的内容
  for (int i = 0; i < vaccine_num; ++i) {
    fprintf(fp, "%lld,%d\n", vaccines[i].id, vaccines[i].type);
  }  // 逐行写入结构体内容
  fclose(fp);
  return 0;
}

// 查找疫苗信息
int SearchVaccine(long long id) {
  for (int i = 0; i < vaccine_num; ++i) {
    if (vaccines[i].id == id) {
      return i;
    }
  }
  return -1;
};

// 增加疫苗信息，成功返回0，失败-1
int AddVaccine(Vaccine new_vaccine) {
  int index = SearchVaccine(new_vaccine.id);
  if (index != -1) {
    printf("存在编号相同的疫苗\n");
    return -1;
  } else {
    vaccines[vaccine_num] = new_vaccine;
    vaccine_num++;
    WriteVaccine();
  }
  return 0;
};

// 删除疫苗信息，成功返回0，失败-1
int DeleteVaccine(long long id) {
  int index = SearchVaccine(id);
  if (index == -1) {
    return -1;
  } else {
    FILE* fp;  // 打开数据文件
    if ((fp = fopen(VaccinePath, "w")) == NULL) {
      printf("打开文件%s错误\n", VaccinePath);
      return -1;
    }
    fprintf(fp, "id,type,\n");  // 写入第一行（标题）的内容
    for (int i = 0; i < vaccine_num; ++i) {
      if (i == index) continue;
      fprintf(fp, "%lld,%d\n", vaccines[i].id, vaccines[i].type);
    }  // 逐行写入结构体内容
    fclose(fp);
    vaccine_num = 0;
    ReadVaccine();
  }
  return 0;
};

// 修改疫苗信息
void EditVaccine() {
  printf("请输入需要修改的疫苗ID: ");
  long long id;
  scanf("%lld", &id);
  int index = SearchVaccine(id);
  if (index == -1) {
    printf("不存在该疫苗\n");
  } else {
    printf("需要修改的疫苗信息\n");
    printf("ID:%lld 种类:%s\n", vaccines[index].id,
           vaccine_type[vaccines[index].type]);
    for (int i = 0; i < VACCINENUM; ++i) {
      printf("%d: %s\n", i + 1, vaccine_type[i]);
    }
    printf("请输入修改后的的疫苗的种类数字: ");
    scanf("%d", &vaccines[index].type);
    WriteVaccine();
    printf("修改成功\n");
  }
};
