#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<signal.h>
#include<fcntl.h>



int main(){
    pid_t child1,child2,childnofc2;

    //creating the named pipe
    if(mkfifo("named_pipe",0777) == -1){
        if (errno!=EEXIST){
            printf("Could not create named pipe\n");
        }        
    }

    //create first child of parent
    child1 = fork();
    if(child1 == -1){
        printf("Can not create Listener Process\n");
        return 1;
    }
    else if(child1 == 0){
        int x;
        
        //pipe reader    
        for(int i = 0;i<20;i--){        
            int fd = open("named_pipe",O_RDONLY);
            if(fd == -1){
                printf("faild to open read fd\n");
            }
            if(read(fd,&x,sizeof(int))== -1){
                printf("faild to  read fd\n");
            }
            printf("Read %d\n",x);
            fflush(stdout);
                
            close(fd);
           
            
        }
        
        return 0;
    }


    //create second child process
    child2 = fork();
    if(child2 == -1){
        printf("Can not create Reader Process\n");
        return 1;
    }
    else if(child2 == 0){
        child2 = getpid();
        int n;
        for(int i = 0;i<20;i++){
            
            childnofc2 = fork();
            if(childnofc2 == -1){
                printf("Can not create child process: %u \t iteration: %d \n",childnofc2,i+1);
            }
            else if(childnofc2 == 0){
                              
                int fd = open("named_pipe",O_WRONLY);
                if(fd == -1){
                    printf("faild open %d\n",i);
                }
                if(write(fd,&i,sizeof(int))== -1){
                    printf("faild writing %d\n",i);
                }
                
                close(fd);
                
                exit(0);
            }

            wait(NULL);
        
        } 

        //sending a signal to the lister process to to terminate.
        kill(child1,SIGTERM);

        return 0;
    }

    wait(NULL);
    wait(NULL);


    return 0;
}