#ifndef _VACCINE_H
#define _VACCINE_H

#define VACCINEMAX 5000

#define VACCINENUM 7  // 疫苗种数

// 疫苗信息
typedef struct {
  long long id;  // 疫苗唯一ID编号
  int type;      // 疫苗种类
} Vaccine;
Vaccine vaccines[VACCINEMAX];

// 读取 VaccinePath 中的数据到结构体，成功返回0，失败-1
int ReadVaccine();

// 将结构体写入文件，成功返回0，失败-1
int WriteVaccine();

// 增加疫苗信息，成功返回0，失败-1
int AddVaccine();

// 删除疫苗信息，成功返回0，失败-1
int DeleteVaccine();

// 查找疫苗信息
void SearchVaccine(long long id);

// 修改疫苗信息
void EditVaccine(long long id);

#endif