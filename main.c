#include <stdio.h>
#include <stdlib.h>

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
                  case 1:
                    if (!AddDoctor()) {
                      printf("添加失败\n");
                    } else {
                      printf("添加成功\n");
                    }
                    break;
                  case 2:
                    if (!DeleteDoctor()) {
                      printf("删除失败\n");
                    } else {
                      printf("删除成功\n");
                    }
                    break;
                  case 3: {
                    printf("请输入需要查询的医生ID: ");
                    long long id;
                    scanf("%lld", &id);
                    SearchDoctor(id);
                  } break;
                  case 4: {
                    printf("请输入需要修改的医生ID: ");
                    long long id;
                    scanf("%lld", &id);
                    EditDoctor(id);
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
                  case 1:
                    if (!AddPerson()) {
                      printf("添加失败\n");
                    } else {
                      printf("添加成功\n");
                    }
                    break;
                  case 2:
                    if (!DeletePerson()) {
                      printf("删除失败\n");
                    } else {
                      printf("删除成功\n");
                    }
                    break;
                  case 3: {
                    printf("请输入需要查询的接种者身份证号: ");
                    char id[20];
                    scanf("%s", id);
                    SearchPerson(id);
                  } break;
                  case 4: {
                    printf("请输入需要修改的接种者身份证号: ");
                    char id[20];
                    scanf("%s", id);
                    EditPerson(id);
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
            case 1:
              if (!AddVaccine()) {
                printf("添加失败\n");
              } else {
                printf("添加成功\n");
              }
              break;
            case 2:
              if (!DeleteVaccine()) {
                printf("删除失败\n");
              } else {
                printf("删除成功\n");
              }
              break;
            case 3: {
              printf("请输入需要查询的疫苗ID: ");
              long long id;
              scanf("%lld", &id);
              SearchVaccine(id);
            } break;
            case 4: {
              printf("请输入需要修改的疫苗ID: ");
              long long id;
              scanf("%lld", &id);
              EditVaccine(id);
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
            case 1:
              if (!AddRecord()) {
                printf("添加失败\n");
              } else {
                printf("添加成功\n");
              }
              break;
            case 2:
              if (!DeleteRecord()) {
                printf("删除失败\n");
              } else {
                printf("删除成功\n");
              }
              break;
            case 3: {
              printf("请输入需要查询接种记录人员的身份证号: ");
              char id[20];
              scanf("%s", id);
              SearchRecord(id);
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