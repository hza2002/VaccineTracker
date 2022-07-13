#ifndef _GENERATE_H
#define _GENERATE_H

#define DOCTORMAX 5000
#define PERSONMAX 5000
#define VACCINEMAX 5000
#define RECORDMAX 5000
#define HospitalNum 14
#define DoctorNum 53
#define PersonNum 157
#define VaccineNum 200
#define VACCINENUM 7  // 疫苗种数

// 医生信息
typedef struct {
  long long id;       // 医生唯一ID编号
  char name[30];      // 姓名
  char hospital[80];  // 所属医院
} Doctor;
Doctor doctors[DOCTORMAX];

// 接种者信息
typedef struct {
  char id[20];    // 身份证号
  char name[30];  // 姓名
  int gender;     // 性别，0代表男性，1代表女性
} Person;
Person persons[PERSONMAX];

// 疫苗信息
typedef struct {
  long long id;  // 疫苗唯一ID编号
  int type;      // 疫苗种类
} Vaccine;
Vaccine vaccines[VACCINEMAX];

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

// 医生数据生成
int DoctorDataGenerate();
// 接种者信息生成
int PersonDataGenerate();
// 疫苗信息生成
int VaccineDataGenerate();
// 接种信息生成
int RecordDataGenerate();

#endif