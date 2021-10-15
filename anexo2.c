main(){
  int ret;
  ret = fork();
  if (ret == 0){
    execl("/bin/ls","ls", 0);
  }
  else{
    printf("Processo continua executando.\n");
  }
}