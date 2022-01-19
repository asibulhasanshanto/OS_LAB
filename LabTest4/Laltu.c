#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{

	char folderPath[200];
	pid_t Laltu,Ittu,Bittu,Mittu;
	int a,b;
	char aString[10],bString[10];
	int *wstatus,*wstatus2,*wstatus3;


	scanf("%d",&a);
	scanf("%d",&b);

	sprintf(aString,"%d",a);
	sprintf(bString,"%d",b);


	
	strcpy(folderPath,"/home/cseru/Desktop/Asibul/OS_LAB/Labexam4");
	//create three child proces of laltu
	Ittu = fork();
	if(Ittu == -1){
        printf("Can not create Ittu \n");
    }
    else if(Ittu == 0){//child ittu
        int status1= execlp(strcat(folderPath,"/ittu"),aString,bString,NULL);
		if(status1==-1){
			printf("please compile Ittu like(gcc Ittu.c -o ittu) \n");
		}       
    }
    else if(Ittu > 0){//parent process
		Bittu = fork();
		if(Bittu == -1){
        	printf("Can not create Bittu \n");
    	}
    	else if(Bittu == 0){//child bittu
        	int status2=execlp(strcat(folderPath,"/bittu"),"bittu",NULL);
			if(status2==-1){
				printf("please compile Bittu like(gcc Bittu.c -o bittu) \n");
			}        
    	}
		else if(Bittu>0){//parent process
			Mittu = fork();
			if(Mittu == -1){
        		printf("Can not create Mittu \n");
    		}
			else if(Mittu ==0){//child mittu
				int status3=execlp(strcat(folderPath,"/mittu"),"mittu",NULL);
				if(status3==-1){
					printf("please compile Mttu like(gcc Mittu.c -o mittu)before running laltu \n");
				} 
			}
			else if(Mittu>0){
				wait(wstatus3);
			}

			wait(wstatus2);
		}

		wait(wstatus);
	}
    
	return 0;
}
