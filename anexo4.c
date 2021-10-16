#include <stdio.h>

void main(){
  int ret;
  ret = fork();
  if (ret == 0){
    execl("/bin/ll","ll", 0);
    printf("Por que este comando foi executado ? \n");
  }
  else{
    printf("Processo continua executando.\n");
  }
}