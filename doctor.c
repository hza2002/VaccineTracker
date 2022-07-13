#include "doctor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DoctorPath = "data/doctor.csv";
int doctor_num = 0;  // 医生数量

// 读取 DoctorPath 中的数据到结构体，成功返回0，失败-1
int ReadDoctor() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(DoctorPath, "r")) == NULL) {
    printf("打开文件%s错误\n", DoctorPath);
    return -1;
  }
  char buffer[1024];
  fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
  while (!feof(fp)) {
    fscanf(fp, "%lld,%s,%s", &doctors[doctor_num].id, doctors[doctor_num].name,
           doctors[doctor_num].hospital);
    doctor_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}