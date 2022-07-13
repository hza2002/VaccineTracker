#include "person.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* PersonPath = "/data/person.csv";
int person_num = 0;  // 接种者数量

// 读取 PersonPath 中的数据到结构体，成功返回0，失败-1
int ReadPerson() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(PersonPath, "r")) == NULL) {
    printf("打开文件%s错误\n", PersonPath);
    return -1;
  }
  char buffer[1024];
  fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
  while (!feof(fp)) {
    fscanf(fp, "%s,%s,%d\n", persons[person_num].id, persons[person_num].name,
           &persons[person_num].gender);
    person_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}