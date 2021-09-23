 //get process id and it's parent process id and also kill them using kill command. ps command shows all the process
#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid,ppid;
    for(int i = 0;i<1;i--){
        pid = getpid();
    ppid = getppid();
    printf("PID: %u\n",pid);
    printf("PPID: %u\n",ppid);
    }



    return 0;
}
