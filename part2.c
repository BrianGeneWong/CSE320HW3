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
		char* app=NULL;
		if (fileName==NULL){
			errno=ENOENT;
			perror("INPUT FILENAME");
			return errno;

		}
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
			app="app1";
			input=fopen(fileName,"r");
			if(input==NULL){
				perror("FILE NOT FOUND ERROR");
				return errno;	
			}
			fclose(input);
			
		}
		else if(strcmp(command,"trace")==0){
			app="app2";
			input=fopen(fileName,"r");
			if(input==NULL){
				perror("FILE NOT FOUND ERROR");
				return errno;	
			}
			fclose(input);

		}
		else if(strcmp(command,"fib")==0){
			
			app="app3";
		
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
				argv[1]=fileName;
				execve(app,argv,NULL);

			}
			waitpid(pid,&status,0);
			

		}
		free(command);
	}
	
}
