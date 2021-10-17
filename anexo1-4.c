#include <stdio.h>
#include <unistd.h>

void main(){
  int ret;
  ret = fork();
  if (ret == 0){
    printf("%d\n", ret);
    execl("/bin/ll","ll", NULL);
    printf("Por que este comando foi executado ? \n");
  }
  else{
    printf("%d\n", ret);
    printf("Processo continua executando.\n");
  }
}