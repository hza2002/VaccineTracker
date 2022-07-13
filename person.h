#ifndef _PERSON_H
#define _PERSON_H

#define PERSONMAX 5000

// 接种者信息
typedef struct {
  char id[20];    // 身份证号
  char name[20];  // 姓名
  int gender;     // 性别，0代表男性，1代表女性
} Person;
Person persons[PERSONMAX];

// 读取 PersonPath 中的数据到结构体，成功返回0，失败-1
int ReadPerson();

// 将结构体写入文件，成功返回0，失败-1
int WritePerson();

// 增加接种者信息，成功返回0，失败-1
int AddPerson();

// 删除接种者信息，成功返回0，失败-1
int DeletePerson();

// 查找接种者信息
void SearchPerson(char id[]);

// 修改接种者信息
void EditPerson(char id[]);

#endif
