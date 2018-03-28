#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float function(int n, float array){
	int i=n;
	double sum=0;	
	while(i>=0){
		i++;	
	}	
	return  0;
}
int app1(FILE* input){
	float e,a,b,c;
	int n;
	fscanf(input,"%d %f %f %f",&n,&e,&a,&b);
	float array[n+1];
	if(a>=b){

	}
	//psuedocode!
	while(1){
		c=(a+b)/2;
		if(c==0)
			break;
		if((b-a)/2<e)
			break;
		
	}
	printf("%f\n",c);
	FILE *solver=fopen("part2_solver.dat","w");
	//output c to file solver
	return 0;
}
int app2(){
	
}

int app3(){

}


int main(){
	char* openFile;
	FILE* fileName;
	printf("Input Filename\n");
	scanf("%s",openFile);
	fileName=fopen(openFile,"r");
	if(fileName==NULL){
		return errno;
	}
	char* operation;
	printf("Input operation\n");
	scanf("%s",operation);
	if(strcmp(operation,"solver")==0){
		app1(fileName);
	}

	return 0;
}
