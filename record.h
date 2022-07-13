#ifndef _RECORD_H
#define _RECORD_H

#define RECORDMAX 5000

// 接种信息
typedef struct {
  long long id;          // 接种信息唯一ID编号
  char person_id[20];    // 接种者身份证号
  long long doctor_id;   // 接种医生编号
  long long vaccine_id;  // 接种疫苗编号
  // 疫苗接种时间
  int year;
  int month;
  int day;
} Record;
Record records[RECORDMAX];

// 读取 RecordPath 中的数据到结构体，成功返回0，失败-1
int ReadRecord();

// 将结构体写入文件，成功返回0，失败-1
int WriteRecord();

// 增加接种信息，成功返回0，失败-1
int AddRecord();

// 删除接种信息，成功返回0，失败-1
int DeleteRecord();

// 查找接种信息
void SearchRecord(char person_id[]);

#endif