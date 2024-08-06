#include "main/display.h"

#include <stdio.h>

int Menu0() {  // 初始菜单
    int instruction;
    printf(
            "-----疫苗接种管理系统-----\n"
            "    1. 人员管理\n"
            "    2. 疫苗信息管理\n"
            "    3. 接种信息管理\n"
            "    4. 退出系统\n"
            "-----------------------\n");
    scanf("%d", &instruction);
    return instruction;
}

int Menu1() {  // 菜单1
    int instruction;
    printf(
            "--------人员管理--------\n"
            "    1. 医生信息管理\n"
            "    2. 接种者信息管理\n"
            "    3. 返回上级目录\n"
            "----------------------\n");
    scanf("%d", &instruction);
    return instruction;
}

int Menu1_1() {  // 菜单1.1
    int instruction;
    printf(
            "------医生信息管理------\n"
            "    1. 增加医生信息\n"
            "    2. 删除医生信息\n"
            "    3. 查找医生信息\n"
            "    4. 修改医生信息\n"
            "    5. 返回上级目录\n"
            "---------------------\n");
    scanf("%d", &instruction);
    return instruction;
}

int Menu1_2() {  // 菜单1.2
    int instruction;
    printf(
            "-----接种者信息管理-----\n"
            "    1. 增加接种者信息\n"
            "    2. 删除接种者信息\n"
            "    3. 查找接种者信息\n"
            "    4. 修改接种者信息\n"
            "    5. 返回上级目录\n"
            "-------------------\n");
    scanf("%d", &instruction);
    return instruction;
}

int Menu2() {  // 菜单2
    int instruction;
    printf(
            "------疫苗信息管理------\n"
            "    1. 增加疫苗信息\n"
            "    2. 删除疫苗信息\n"
            "    3. 查找疫苗信息\n"
            "    4. 修改疫苗信息\n"
            "    5. 返回上级目录\n"
            "---------------------\n");
    scanf("%d", &instruction);
    return instruction;
}

int Menu3() {  // 菜单3
    int instruction;
    printf(
            "------接种信息管理------\n"
            "    1. 增加接种信息\n"
            "    2. 删除接种信息\n"
            "    3. 查找接种信息\n"
            "    4. 返回上级目录\n"
            "---------------------\n");
    scanf("%d", &instruction);
    return instruction;
}