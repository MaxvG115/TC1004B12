#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2];
    pipe(fd);
    int pid = fork();
    if(pid == 0){
        //close(0);
        dup2(1,fd[0]);
        execlp("wc","wc","-1",NULL);
    }
    else{
        //close(1);
        dup2(1,fd[0]);
        execlp("ls","ls","-1",NULL);
    }
    return 0;
}