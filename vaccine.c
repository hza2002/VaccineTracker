#include "vaccine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* VaccinePath = "/data/vaccine.csv";
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
  if ((fp = fopen(VaccinePath, "w")) == NULL) {
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