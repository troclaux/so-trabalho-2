#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
  int status;
  char *comando;
  comando = argv[1];
  char parametros[] = "";
  for(int i = 2; i < argc; i++) {
    strcat(parametros, argv[i]);
    strcat(parametros, " ");
  }
  printf("%s \n", parametros);
  //enquanto nao fim faça
  while(1){
    int ret = fork();

    if (ret == 0){
      printf("filho \n");
      //usar o comando que foi lido anteriormente
      execl(comando, comando, parametros, NULL);
      printf("\n");
    }else{
      wait(&status);
      if(status == 0){
        printf("Executado com sucesso \n");
      }else{
        printf("Código de retorno = %d \n", status);
      }
    }
    exit(0);
  }
}