#include <stdio.h>
#include <unistd.h>

void main(){
  int ret;
  ret = fork();

  if (ret == 0){
    execl("/bin/ls","ls", NULL);
    printf("Quando este comando será executado ? \n");
  };
  printf("Por que a função printf anterior não foi executada?\n");
}