#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){
  int status, retorno, option;
  char *comando;
  comando = argv[1];
  
  while(1){
    int ret = fork();

    if (ret == 0){
      retorno = execv(comando, &argv[1]);
      
      if(retorno == -1){
        printf("Comando não encontrado\n");
        return -1;
      }
    } else {
      wait(&status);
      if(status == 0) {
        printf("Filho terminou a execução com sucesso! \n");
      } else if(status != 0) {
        printf("Filho terminou a execução com falha! \n");
        printf("Código de retorno = %d \n", status);
      }
    }
    exit(0);
  }
}