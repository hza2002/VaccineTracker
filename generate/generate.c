#include "generate.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "snowflake.h"

char* DoctorPath = "../data/doctor.csv";
char* PersonPath = "../data/person.csv";
char* VaccinePath = "../data/vaccine.csv";
char* RecordPath = "../data/record.csv";

int doctor_num = 0;   // 医生数量
int person_num = 0;   // 接种者数量
int vaccine_num = 0;  // 疫苗数量
int record_num = 0;   // 接种信息数量

char hospital_list[HospitalNum][100] = {
    "重庆儿童医院(重庆医科大学附属儿童医院)",
    "重庆新桥医院",
    "中国人民解放军三二四医院",
    "武警重庆总队医院",
    "重庆三峡中心医院",
    "重庆市红十字会医院",
    "重庆市涪陵中心医院",
    "重庆市第九人民医院",
    "重庆市急救医疗中心",
    "重庆市肿瘤医院",
    "重庆医科大学附属口腔医院",
    "重庆医科大学附属第二医院",
    "重庆医科大学附属永川医院",
    "重庆医科大学附属儿童医院禮嘉分校,"};

char doctor_list[DoctorNum][30] = {
    "艾陈芳", "王特",   "杨坤",   "李蕾",   "刘佳",   "孙亚萍", "姜涛",
    "赵思蕊", "解茹姗", "王小丹", "赵凌洁", "陈振和", "薛国亚", "佘颖禾",
    "刘振田", "单炳梓", "杨汉国", "唐九如", "吕培贞", "方先和", "姚梓华",
    "陶光华", "马裕音", "冯秀娟", "张平",   "童启明", "黄安永", "张淑芳",
    "王功勋", "肖士者", "韩苏闽", "赵惠麟", "王锦麒", "朱康英", "江亚英",
    "赵希久", "吴慧新", "张星",   "姜明燊", "郑建芳", "肖勉",   "陆可人",
    "李世昌", "周志红", "许翥中", "张蔼玲", "林坚",   "朱继澄", "沈杰",
    "林循泓", "宋启根", "邓其萱", "樊发兴",
};

char person_list[PersonNum][30] = {
    "丁红朝", "马春宇", "尹明柴", "付荣华", "冯克江", "朱艳峰", "刘科江",
    "齐攀",   "买琳燕", "杨震伦", "吴隽",   "张勇",   "陆明祥", "陈基纯",
    "陈惠红", "陈湘平", "赵聚雪", "胡耀民", "段娜",   "侯文峰", "徐梦漪",
    "高鹏",   "盛永华", "童丽",   "曾卉",   "曾衍文", "詹增荣", "蔡柳萍",
    "蔡小路", "曹继娟", "曾令权", "陈海山", "陈秀梅", "陈宜国", "谌丹",
    "程钰淇", "程院莲", "仇授书", "代慧",   "邓白君", "邓永平", "翟丽娜",
    "丁玉红", "窦艳",   "杜素音", "高燕",   "关霓",   "郭红霞", "郭连红",
    "郭全美", "郝丽萍", "何华",   "黄琛",   "黄洁琦", "黄丽丽", "黄美灵",
    "黄映雪", "黄有福", "黄泽文", "金莉莉", "金迎迎", "孔巧丽", "李常能",
    "李海欢", "李霞",   "李晓跃", "李燕霞", "李子莹", "梁文晓", "林祖乐",
    "刘鲲",   "刘希",   "刘云",   "罗书嵘", "莫裕醒", "欧越男", "潘瑾",
    "裴小妮", "秦铭谦", "任碧峰", "任岩岩", "石慧",   "石先兵", "汪雯波",
    "王超辉", "王珏",   "王蕾蕾", "王丽娜", "王书玮", "魏爱敏", "谢艳霜",
    "玄颖双", "闫黎",   "杨井兰", "杨柳",   "杨宪福", "杨智翼", "张春霞",
    "张莉萍", "张雯",   "张雨红", "张占辉", "赵佳",   "钟闰禄", "钟晓玲",
    "丁镇裕", "万绮思", "卫婵",   "王雪",   "王鹏",   "尹诗雨", "吕润玲",
    "刘文惠", "刘亚楠", "刘强",   "孙晓龙", "孙道明", "纪丽芝", "苏叶子",
    "杜满聪", "李海楠", "杨立军", "杨秀",   "杨金玲", "杨秋苑", "杨璐",
    "吴晓亚", "吴镇宣", "邱华愉", "邱晨瑜", "何玮",   "何嘉鸿", "余一鸣",
    "张云茜", "张圣翎", "张倩",   "张雅楠", "林惠媛", "罗文升", "罗梦",
    "罗锦雯", "庞伟涛", "赵国栋", "赵惟琦", "钟阁",   "钟晓天", "段琪",
    "高一晓", "高圆珊", "陶丽萍", "黄日财", "黄苏苏", "黄洁",   "营鑫妍",
    "梁炬强", "彭姗",   "谢澌祺"};

// 疫苗信息
char vaccine_type[VACCINENUM][30] = {
    "北京生物新冠疫苗", "科兴中维新冠疫苗", "武汉生物新冠疫苗",
    "康希诺新冠疫苗",   "智飞新冠疫苗",     "康泰新冠疫苗",
    "医科生物新冠疫苗",
};

// 医生数据生成
int DoctorDataGenerate() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(DoctorPath, "w")) == NULL) {
    printf("打开文件%s错误\n", DoctorPath);
    return -1;
  }
  fprintf(fp, "id,name,hospital\n");  // 写入第一行（标题）的内容
  for (int i = 0; i < DoctorNum; ++i) {
    doctors[doctor_num].id = next_id();
    strcpy(doctors[doctor_num].name, doctor_list[doctor_num]);
    strcpy(doctors[doctor_num].hospital, hospital_list[rand() % HospitalNum]);
    fprintf(fp, "%lld,%s,%s\n", doctors[doctor_num].id,
            doctors[doctor_num].name, doctors[doctor_num].hospital);
    doctor_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}

// 接种者数据生成
int PersonDataGenerate() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(PersonPath, "w")) == NULL) {
    printf("打开文件%s错误\n", PersonPath);
    return -1;
  }
  fprintf(fp, "id,name,gender\n");  // 写入第一行（标题）的内容
  for (int i = 0; i < PersonNum; ++i) {
    strcpy(persons[person_num].id, "330304200209250313");
    strcpy(persons[person_num].name, person_list[rand() % PersonNum]);
    persons[person_num].gender = rand() % 2;
    fprintf(fp, "%s,%s,%d\n", persons[person_num].id, persons[person_num].name,
            persons[person_num].gender);
    person_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}

// 疫苗数据生成
int VaccineDataGenerate() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(VaccinePath, "w")) == NULL) {
    printf("打开文件%s错误\n", VaccinePath);
    return -1;
  }
  fprintf(fp, "id,type,\n");  // 写入第一行（标题）的内容
  for (int i = 0; i < VaccineNum; ++i) {
    vaccines[vaccine_num].id = next_id();
    vaccines[vaccine_num].type = rand() % VACCINENUM;
    fprintf(fp, "%lld,%d\n", vaccines[vaccine_num].id,
            vaccines[vaccine_num].type);
    vaccine_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}

// 接种记录生成
int RecordDataGenerate() {
  FILE* fp;
  // 打开数据文件
  if ((fp = fopen(RecordPath, "w")) == NULL) {
    printf("打开文件%s错误\n", RecordPath);
    return -1;
  }
  fprintf(fp, "id,person_id,doctor_id,vaccine_id,year,month,day\n");
  for (int i = 0; i < VaccineNum; ++i) {
    records[record_num].id = next_id();
    strcpy(records[record_num].person_id, persons[rand() % PersonNum].id);
    records[record_num].doctor_id = doctors[rand() % DoctorNum].id;
    records[record_num].vaccine_id = vaccines[rand() % VaccineNum].id;
    // 考虑到现实中疫苗在2021年开始大规模注射
    // 而截至程序编写时为2022年7月，故如此分类
    int year = rand() % 2;
    if (year == 0) {
      records[record_num].year = 2021;
      records[record_num].month = 1 + rand() % 11;
    } else {
      records[record_num].year = 2022;
      records[record_num].month = 1 + rand() % 7;
    }
    records[record_num].day = 1 + rand() % 27;
    fprintf(fp, "%lld,%s,%lld,%lld,%d,%d,%d\n", records[record_num].id,
            records[record_num].person_id, records[record_num].doctor_id,
            records[record_num].vaccine_id, records[record_num].year,
            records[record_num].month, records[record_num].day);
    record_num++;
  }  // 逐行获取结构体内容
  fclose(fp);
  return 0;
}