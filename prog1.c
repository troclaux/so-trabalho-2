#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main(void)
{
  int status, id, j;
  int ret; //tem problema fazer aqui ao inves de dentro do if?
  int mensageiroPaiParaFilho[2]; //declara o pipe
  int mensageiroFilhoParaPai[2];

  //Insira um comando para pegar o PID do processo corrente e mostre na tela da console.
  if(pipe(mensageiroPaiParaFilho) == -1){
    printf("deu ruim na mensagem do processo pai para o filho");
    return -1;
  }
  if(pipe(mensageiroFilhoParaPai) == -1){
    printf("deu ruim na mensagem do processo filho para o pai");
    return -1;
  }

  //dentro do if -> insira um comando para criar um subprocesso
  if ((ret = fork()) > 0){

    char str_buffer2[50];
    //Faça com que o processo pai execute este trecho de código
    //Mostre na console o PID do processo pai e do processo filho
    printf("PID do processo pai: %d\n", getpid());
    printf("PID do processo filho: %d\n", ret);
    //Monte uma mensagem e a envie para o processo filho
    char str[] = "mensagem para processo filho";

    //fecha leitura do pipe
    close(mensageiroPaiParaFilho[READ]);

    write(mensageiroPaiParaFilho[WRITE], str, sizeof(str));
    //Mostre na tela o texto da mensagem enviada
    //Aguarde a resposta do processo filho
    //Mostre na tela o texto recebido do processo filho
    //Aguarde mensagem do filho e mostre o texto recebido

    close(mensageiroFilhoParaPai[WRITE]);
    read(mensageiroFilhoParaPai[READ], str_buffer2, sizeof(str_buffer2));
    printf("string recebida do processo filho = %s \n", str_buffer2);

    //Aguarde o término do processo filho
    //Informe na tela que o filho terminou e que o pai também vai encerrar
  }else if(ret == 0){
    // Faça com que o processo filho execute este trecho de código
    // Mostre na tela o PID do processo corrente e do processo pai
    printf("PID do processo pai: %d\n", getppid()); //pega pid do processo pai
    printf("PID do processo filho: %d\n", getpid()); //pega pid do processo filho

    // Aguarde a mensagem do processo pai e ao receber mostre o texto na tela
    close(mensageiroPaiParaFilho[WRITE]); //fecha escrita do pipe
    char str_buffer[50];
    read(mensageiroPaiParaFilho[READ], str_buffer, sizeof(str_buffer));
    printf("string recebida do processo pai = %s \n", str_buffer);
    // Envie uma mensagem resposta ao pai
    char str2[] = "mensagem para processo pai\n";
    close(mensageiroFilhoParaPai[READ]);
    write(mensageiroFilhoParaPai[WRITE], str2, sizeof(str2));
    // Execute o comando "for" abaixo
  //for (j = 0; j <= 10000; j++);
  //Envie mensagem ao processo pai com o valor final de "j"
  //Execute o comando abaixo e responda às perguntas
  //execl("/ Bin / ls", "ls", NULL);
  //O que acontece após este comando ? *****O que pode acontecer se o comando "execl" falhar ?
  }
  exit(0);
}