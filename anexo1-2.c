#include <stdio.h>
#include <unistd.h>

void main(){

  int ret;
  ret = fork();
  if (ret == 0){
    execl("/bin/ls","ls", NULL);
  }
  else{
    printf("Processo continua executando.\n");
  }
}