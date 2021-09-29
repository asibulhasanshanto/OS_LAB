#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<signal.h>

int main(){
    int pid = fork();
    if(pid ==-1){
        return 1;
    }
    if (pid==0)
    {
        //child process
        int i = 0;
        while (1)
        {
            printf("hello:%d\n",i+1);
            usleep(100000);
            i++;
        }
        
    }
    else{
        int t;
        kill(pid, SIGSTOP);
        do{
            printf("enter time for execution: \n");
            scanf("%d",&t);
            if(t>0){
                kill(pid,SIGCONT);
                sleep(t);
                kill(pid, SIGSTOP);
            }

        }while(t>0);
        //parant process
        kill(pid, SIGKILL);
        wait(NULL);

    }

    return 0;
    
}