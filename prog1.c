#include <stdio.h>
#include <wait.h>
#include <unistd.h>
int main(void)
{
  int status, id, j;
  int ret = fork(); //tem problema fazer aqui ao inves de dentro do if?
  //Insira um comando para pegar o PID do processo corrente e mostre na tela da console.

  //dentro do if -> insira um comando para criar um subprocesso
  if (ret > 0){
    //Faça com que o processo pai execute este trecho de código
    //Mostre na console o PID do processo pai e do processo filho
    printf("PID do processo pai: %d\n", getpid());
    printf("PID do processo filho: %d\n", ret);
    //Monte uma mensagem e a envie para o processo filho
    //Mostre na tela o texto da mensagem enviada
    //Aguarde a resposta do processo filho
    //Mostre na tela o texto recebido do processo filho
    //Aguarde mensagem do filho e mostre o texto recebido
    //Aguarde o término do processo filho
    //Informe na tela que o filho terminou e que o pai também vai encerrar
  }else{
    // Faça com que o processo filho execute este trecho de código
    // Mostre na tela o PID do processo corrente e do processo pai
    // Aguarde a mensagem do processo pai e ao receber mostre o texto na tela
    // Envie uma mensagem resposta ao pai
    // Execute o comando "for" abaixo
  for (j = 0; j <= 10000; j++);
  //Envie mensagem ao processo pai com o valor final de "j"
  //Execute o comando abaixo e responda às perguntas
  execl("/ Bin / ls", "ls", NULL);
  //O que acontece após este comando ? *****O que pode acontecer se o comando "execl" falhar ?
  }
  exit(0);
}