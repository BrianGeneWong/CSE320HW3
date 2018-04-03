#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc,char **argv){
	char* fileName=*(argv+1);
	FILE* input;
	while(1){
	char* command=malloc(50);
		pid_t pid;
		int status;
		int fib;
		char* app=NULL;
		if (fileName==NULL){
			errno=ENOENT;
			perror("INPUT FILENAME");
			return errno;

		}
		input=fopen(fileName,"r");
		if(input==NULL){
			perror("FILE NOT FOUND ERROR");
			return errno;	
		}
		fclose(input);
		printf("Please input command: ");
		scanf("%s",command);

		//strcmp the commands
		if(strcmp(command,"quit")==0){
			return(0);
		}
		else if(strcmp(command,"change")==0){
			scanf("%s",argv[1]);
					
			
		}
		else if(strcmp(command,"solver")==0){
			app="solver";
			
		}
		else if(strcmp(command,"trace")==0){
			app="trace";

		}
		else if(strcmp(command,"fib")==0){
			app="fib";
			input=fopen(fileName,"r");
			fscanf(input,"%d",&fib);
//			printf("fib is %d\n",fib);
			fclose(input);
			
			sprintf(argv[1],"%d",fib);	
		}

		else{
			printf("invalid command");
			return -1;

		}

		if(app!=NULL){	
			if((pid=fork())<0){
				perror("Failed to fork");
				return errno;
				
			}
			else if(pid==0){
//				argv[1]=fileName;
				execve(app,argv,NULL);
			}
			
			else{	
			//	waitpid(pid,&status,0);
				wait(NULL);
			}	
		}
		free(command);
	}
	
}
