#define _GNU_SOURCE

#include <pthread.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/syscall.h>
#include <sched.h>


void thread1(){
    int i,cpuNo;
    pid_t pid,threadID;

    for(i=0;i<10;i++){
        pid = getpid();
        threadID = syscall(SYS_gettid);
        cpuNo = sched_getcpu();
        printf("Thread 1 (PID:%d , Thread ID:%d) is running at CPU-%d\n",pid,threadID,cpuNo);
    }
}

void thread2(){
    int i,cpuNo;
    pid_t pid,threadID;

    for(i=0;i<10;i++){
        pid = getpid();
        threadID = syscall(SYS_gettid);
        cpuNo = sched_getcpu();
        printf("Thread 2 (PID:%d , Thread ID:%d) is running at CPU-%d\n",pid,threadID,cpuNo);
    }
}

int main(){
    pid_t pid,threadID,child;
    pthread_t tid1,tid2;
    int i,cpuNo;

    child = fork();
    if(child ==0){
        for(i=0;i<10;i++){
            pid = getpid();
            threadID = syscall(SYS_gettid);
            cpuNo = sched_getcpu();
            printf("Child process Thread main (PID:%d , Thread ID:%d) is running at CPU-%d\n",pid,threadID,cpuNo);
        }
    }else if (child >0){
        pthread_create(&tid1,NULL,(void *) thread1,NULL);
        pthread_create(&tid2,NULL,(void *) thread2,NULL);

        for(i=0;i<10;i++){
            pid = getpid();
            threadID = syscall(SYS_gettid);
            cpuNo = sched_getcpu();
            printf("Thread main (PID:%d , Thread ID:%d) is running at CPU-%d\n",pid,threadID,cpuNo);
        }

        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
    }
    

    
}