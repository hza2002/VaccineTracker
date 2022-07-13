#include <stdio.h>
#include <stdlib.h>

#include "./generate/snowflake.h"
#include "display.h"
#include "doctor.h"
#include "person.h"
#include "record.h"
#include "vaccine.h"

int main() {
  // 读取初始文件数据
  ReadDoctor();
  ReadPerson();
  ReadVaccine();
  ReadRecord();

  // 初始界面
  int continue_flag = 1;
  while (continue_flag) {
    /*------------------- 疫苗接种系统 --------------------*/
    switch (Menu0()) {
      /*------------------- 人员管理 --------------------*/
      case 1: {
        int flag = 1;
        while (flag) {
          switch (Menu1()) {
              /*----------- 医生信息管理 -----------*/
            case 1: {
              int flag = 1;
              while (flag) {
                switch (Menu1_1()) {
                  case 1: {
                    Doctor new_doctor;
                    printf("请输入需要添加的医生ID: ");
                    scanf("%lld", &new_doctor.id);
                    printf("请输入需要添加的医生姓名: ");
                    scanf("%s", new_doctor.name);
                    printf("请输入需要添加的医生所属医院: ");
                    scanf("%s", new_doctor.hospital);
                    if (AddDoctor(new_doctor) == -1) {
                      printf("添加失败\n");
                    } else {
                      printf("添加成功\n");
                    }
                  } break;
                  case 2: {
                    printf("请输入需要删除的医生ID: ");
                    long long id;
                    scanf("%lld", &id);
                    if (DeleteDoctor(id) == -1) {
                      printf("删除失败\n");
                    } else {
                      printf("删除成功\n");
                    }
                  } break;
                  case 3: {
                    printf("请输入需要查询的医生ID: ");
                    long long id;
                    scanf("%lld", &id);
                    int index = SearchDoctor(id);
                    if (index == -1) {
                      printf("不存在该医生\n");
                    } else {
                      printf("ID:%lld 姓名:%s 所属医院:%s\n", doctors[index].id,
                             doctors[index].name, doctors[index].hospital);
                    }
                  } break;
                  case 4: {
                    EditDoctor();
                  } break;
                  case 5:
                    flag = 0;
                    break;
                  default:
                    printf("请输入正确的选项\n");
                    break;
                }
              }
            } break;
              /*---------- 接种者信息管理 ----------*/
            case 2: {
              int flag = 1;
              while (flag) {
                switch (Menu1_2()) {
                  case 1: {
                    Person new_person;
                    printf("请输入需要添加的接种者身份证号: ");
                    scanf("%s", new_person.id);
                    printf("请输入需要添加的接种者姓名: ");
                    scanf("%s", new_person.name);
                    printf("请输入需要添加的接种者联系电话: ");
                    scanf("%lld", &new_person.phone);
                    if (AddPerson(new_person) == -1) {
                      printf("添加失败\n");
                    } else {
                      printf("添加成功\n");
                    }
                  } break;
                  case 2: {
                    printf("请输入需要删除的接种者身份证号: ");
                    char id[20];
                    scanf("%s", id);
                    if (DeletePerson(id) == -1) {
                      printf("删除失败\n");
                    } else {
                      printf("删除成功\n");
                    }
                  } break;
                  case 3: {
                    printf("请输入需要查询的接种者身份证号: ");
                    char id[20];
                    scanf("%s", id);
                    int index = SearchPerson(id);
                    if (index == -1) {
                      printf("不存在该医生\n");
                    } else {
                      printf("身份证号:%s 姓名：%s 联系方式:%lld\n",
                             persons[index].id, persons[index].name,
                             persons[index].phone);
                    }
                  } break;
                  case 4: {
                    EditPerson();
                  } break;
                  case 5:
                    flag = 0;
                    break;
                  default:
                    printf("请输入正确的选项\n");
                    break;
                }
              }
            } break;
            case 3:
              flag = 0;
              break;
            default:
              printf("请输入正确的选项\n");
              break;
          }
        }
      } break;
      /*----------------- 疫苗信息管理 ------------------*/
      case 2: {
        int flag = 1;
        while (flag) {
          switch (Menu2()) {
            case 1: {
              Vaccine new_vaccine;
              printf("请输入需要添加的疫苗ID: ");
              scanf("%lld", &new_vaccine.id);
              for (int i = 0; i < VACCINENUM; ++i) {
                printf("%d: %s", i + 1, vaccine_type[i]);
              }
              printf("请输入需要添加的疫苗种类数字: ");
              scanf("%d", &new_vaccine.type);
              if (AddVaccine(new_vaccine) == -1) {
                printf("添加失败\n");
              } else {
                printf("添加成功\n");
              }
            } break;
            case 2: {
              printf("请输入需要删除的疫苗ID: ");
              long long id;
              scanf("%lld", &id);
              if (DeleteVaccine(id) == -1) {
                printf("删除失败\n");
              } else {
                printf("删除成功\n");
              }
            } break;
            case 3: {
              printf("请输入需要查询的疫苗ID: ");
              long long id;
              scanf("%lld", &id);
              int index = SearchVaccine(id);
              if (index == -1) {
                printf("不存在该疫苗\n");
              } else {
                printf("ID:%lld 种类:%s\n", vaccines[index].id,
                       vaccine_type[vaccines[index].type]);
              }
            } break;
            case 4: {
              EditVaccine();
            } break;
            case 5:
              flag = 0;
              break;
            default:
              printf("请输入正确的选项\n");
              break;
          }
        }
      } break;
      /*----------------- 接种信息管理 ------------------*/
      case 3: {
        int flag = 1;
        while (flag) {
          switch (Menu3()) {
            case 1: {
              Record new_record;
              new_record.id = next_id();
              printf("请输入接种者的身份证号码: ");
              scanf("%s", new_record.person_id);
              printf("请输入接种医生ID: ");
              scanf("%lld", &new_record.doctor_id);
              printf("请输入接种疫苗ID: ");
              scanf("%lld", &new_record.vaccine_id);
              printf("请输入接种年份: ");
              scanf("%d", &new_record.year);
              printf("请输入接种月份: ");
              scanf("%d", &new_record.month);
              printf("请输入接种日期: ");
              scanf("%d", &new_record.day);
              if (AddRecord(new_record) == -1) {
                printf("添加失败\n");
              } else {
                printf("添加成功,接种记录ID: %lld\n", new_record.id);
              }
            } break;
            case 2: {
              printf("请输入需要删除的接种ID: ");
              long long id;
              scanf("%lld", &id);
              if (DeleteRecord(id) == -1) {
                printf("删除失败\n");
              } else {
                printf("删除成功\n");
              }
            } break;
            case 3: {
              printf("请输入需要查询的接种记录ID: ");
              long long id;
              scanf("%lld", &id);
              int index = SearchRecord(id);
              if (index == -1) {
                printf("不存在该接种记录\n");
              } else {
                int person_index = SearchPerson(records[index].person_id);
                int doctor_index = SearchDoctor(records[index].doctor_id);
                int vaccine_index = SearchVaccine(records[index].vaccine_id);
                printf("接种人身份证号: %s 姓名：%s 联系电话: %lld\n",
                       persons[person_index].id, persons[person_index].name,
                       persons[person_index].phone);
                printf("接种医生ID: %lld 姓名: %s 所属医院: %s\n",
                       doctors[doctor_index].id, doctors[doctor_index].name,
                       doctors[doctor_index].hospital);
                printf("接种疫苗ID: %lld 疫苗种类: %s\n ",
                       vaccines[vaccine_index].id,
                       vaccine_type[vaccines[vaccine_index].type]);
                printf("接种日期: %d-%d-%d\n", records[index].year,
                       records[index].month, records[index].day);
              }
            } break;
            case 4:
              flag = 0;
              break;
            default:
              printf("请输入正确的选项\n");
              break;
          }
        }
      } break;
      case 4:  // 退出系统
        continue_flag = 0;
        break;
      default:
        printf("请输入正确的选项\n");
        break;
    }
  }

  return 0;
}