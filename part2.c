#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

double function(double c, int n, double array[]){
	double sum=0;
	int index=0;	
	double temp;
	while(n>=0){
		temp=pow(c,n);
		temp=temp*(array[index]);
		sum+=temp;
		index++;
		n--;	
	}	
	return  sum;
}
void app1(/*FILE* input*/){
	FILE *input;
	input=fopen("input.txt","r");
	printf("app1 start \n");
	double e,a,b,c;
	int n;
	fscanf(input,"%d %lf %lf %lf",&n,&e,&a,&b);
//	printf("n= %d, e= %lf, A= %lf, B= %lf\n",n,e,a,b);
	double array[n+1];
	int i=0;
	while(i<n+1){
		fscanf(input,"%lf",&array[i]);
//		printf("array[%d]=%lf ",i,array[i]);
		i++;
	}
	//psuedocode!
	while(1){
		c=(a+b)/2;
		if(c==0)
			break;
		if((b-a)/2<e)
			break;
		//if sign (f(c))=sign(f(a)) then  a<-c else b<- c
                double fOfC=function(c,n,array);
		double fOfA=function(a,n,array);
		if( fOfC*fOfA>0){
			a=c;
		}
		else
			b=c;
	}
	printf("\nc=%f\n",c);
	FILE *solver=fopen("part2_solver.dat","w+");
	fprintf(solver,"%lf",c);
	fclose(solver);
}
void app2(uint64_t n){

	uint64_t array[n+1];
	if(n==0)
		printf("0\n");
	if(n==1)
		printf("1\n");
		
	array[0]=0;
	array[1]=1;

	uint64_t i=2;
	while(i<=n){
		array[i]=array[i-1]+array[i-2];
		i++;
	}
	printf("array[n]= %lu\n", array[n]);
	

}
//fibonacci
void app3(){
	
}


int main(){
	app2(93);
/*
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
*/
	return 0;
}
