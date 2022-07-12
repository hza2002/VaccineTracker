#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数返回fname指定文件的全部内容，如果打不开文件，则返回NULL，并显示打开文件错误
char *getfileall(char *fname) {
  FILE *fp;
  char *str;
  char txt[1000];
  int filesize;

  //打开一个文件
  if ((fp = fopen(fname, "r")) == NULL) {
    printf("打开文件%s错误\n", fname);
    return NULL;
  }

  //将文件指针移到末尾
  fseek(fp, 0, SEEK_END);
  filesize = ftell(fp);  //通过ftell函数获得指针到文件头的偏移字节数。
  str = (char *)malloc(filesize);           //动态分配str内存
  memset(str, 0, filesize * sizeof(char));  //清空数组,字符串置空第二种用法
  rewind(fp);

  while ((fgets(txt, 1000, fp)) !=
         NULL) {  //循环读取1000字节,如果没有数据则退出循环
    strcat(str, txt);  //拼接字符串
  }
  fclose(fp);
  return str;
}

// 测试代码
// int main(int argc, char *argv[]) {
//   char *p;
//   char *fname = "test.txt";
//   p = getfileall(fname);
//   if (p != NULL) puts(p);  //输出字符串p
//   return 0;
// }