#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main(void)
{
  int status, id, j;
  int ret;
  int mensageiroPaiParaFilho[2];
  int mensageiroFilhoParaPai[2];
  char *mensagem;

  if(pipe(mensageiroPaiParaFilho) == -1){
    printf("deu ruim na mensagem do processo pai para o filho");
    return -1;
  }
  if(pipe(mensageiroFilhoParaPai) == -1){
    printf("deu ruim na mensagem do processo filho para o pai");
    return -1;
  }

  if ((ret = fork()) > 0){

    close(mensageiroPaiParaFilho[READ]);
    close(mensageiroFilhoParaPai[WRITE]);

    mensagem = "mensagem para processo filho";
    write(mensageiroPaiParaFilho[WRITE], &mensagem, sizeof(mensagem));

    printf("Aguardando resposta do filho\n");
    read(mensageiroFilhoParaPai[READ], &mensagem, sizeof(mensagem));
    printf("------ PAI ------\nPID do processo pai: %d\nPID do processo filho: %d\n", getpid(),ret);
    printf("string recebida do processo filho = %s \n", mensagem);

    read(mensageiroFilhoParaPai[READ], &j, sizeof(j));
    printf("O valor de 'j' segundo o filho é: %d \n", j);

    wait(&status);

    if(status == 0){
      printf("O processo filho encerrou \n");
    }else{
      printf("O processo filho encerrou com falha \n");
    }
    printf("O processo pai encerrou\n");
  }else if(ret == 0){
    close(mensageiroPaiParaFilho[WRITE]);
    close(mensageiroFilhoParaPai[READ]);    

    read(mensageiroPaiParaFilho[READ], &mensagem, sizeof(mensagem));
    printf("------ FILHO -------\nPID do processo pai: %d\nPID do processo filho: %d\n", getppid(), getpid());
    printf("string recebida do processo pai = %s \n", mensagem);

    mensagem = "mensagem para processo pai\n";
    
    write(mensageiroFilhoParaPai[WRITE], &mensagem, sizeof(mensagem));
    for (j = 0; j <= 10000; j++);

    write(mensageiroFilhoParaPai[WRITE], &j, sizeof(j));

    execl("/bin/ls", "ls", NULL);
    //O que acontece após este comando ? 
    //O que pode acontecer se o comando "execl" falhar ?
  }

  exit(0);
}