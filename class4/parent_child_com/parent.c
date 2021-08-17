#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

int main(){
	int pipeFD[2],status;
	pid_t childPID;
    char res1[30];
    char res2[30];
    char value1[30];
    char value2[30];
 
	status = pipe(pipeFD);
	
	if(status == -1){
		printf("Error");
		exit(-1);
	}

	//create a child
	childPID = fork();
	if(childPID == -1){
		printf("Error");
		exit(-1);
	}
	else if(childPID == 0){//child
    execlp("./child","child",itoa(pipeFD[0],res1,10),itoa(pipeFD[1],res2,10),"3","5",NULL);
	}
	else if(childPID > 0){//parent
		wait(NULL);
		printf("parent process is reading the pipe\n");
		close(pipeFD[1]);
		char buffer[200];
		read(pipeFD[0],buffer,sizeof(buffer));
		printf("%s\n",buffer);
	}

	printf("%d\n",status);
	return 0;
}
