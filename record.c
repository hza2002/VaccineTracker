#include "record.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* RecordPath = "/data/record.csv";
int record_num = 0;  // 接种信息数量

// 读取 RecordPath 中的数据到结构体，成功返回0，失败-1
int ReadRecord() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(RecordPath, "w")) == NULL) {
    printf("打开文件%s错误\n", RecordPath);
    return -1;
  }
  char buffer[1024];
  fgets(buffer, sizeof(buffer), fp);  // 获取第一行（标题）的内容
  while (!feof(fp)) {
    fscanf(fp, "%lld,%s,%lld,%lld,%d,%d,%d\n", &records[record_num].id,
           records[record_num].person_id, &records[record_num].doctor_id,
           &records[record_num].vaccine_id, &records[record_num].year,
           &records[record_num].month, &records[record_num].day);
    record_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}