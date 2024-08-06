#ifndef _GENERATE_H
#define _GENERATE_H

// 限制结构体大小
#define DOCTORMAX 5000
#define PERSONMAX 5000
#define VACCINEMAX 5000
#define RECORDMAX 5000

// 实际数量限制
#define HospitalNum 14   // 医院数量
#define DoctorNum 261    // 医生数量
#define PersonNum 917    // 接种人员数量
#define VaccineNum 2000  // 疫苗数量
#define VACCINENUM 7     // 疫苗种数

// 医生信息
typedef struct {
    long long id;       // 医生唯一ID编号
    char name[20];      // 姓名
    char hospital[80];  // 所属医院
} Doctor;
Doctor doctors[DOCTORMAX];

// 接种者信息
typedef struct {
    char id[20];      // 身份证号
    char name[20];    // 姓名
    long long phone;  // 联系电话
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