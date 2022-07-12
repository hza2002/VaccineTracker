#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm *info;
  char buffer[80];

  time(&rawtime);

  info = localtime(&rawtime);

  strftime(buffer, 80, "%Y%m%e_%H%M%S",
           info);  //以年月日_时分秒的形式表示当前时间
  printf("%s\n", buffer);

  return (0);
}