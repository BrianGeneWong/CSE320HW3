#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double function(double c, int n, double array[]){
	printf("\nCalculating f(c)\n");
	printf("c is %lf n is %d\n",c,n);
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
	printf("f(c)=%lf\n", sum);
	return  sum;
}
int main(/*FILE* input*/){
	FILE *input;
	input=fopen("input.txt","r");
	printf("app1 start \n");
	double e,a,b,c;
	int n;
	fscanf(input,"%d %lf %lf %lf",&n,&e,&a,&b);
	printf("n= %d, e= %lf, A= %lf, B= %lf\n",n,e,a,b);
	double array[n+1];
	int i=0;
	while(i<n+1){
		fscanf(input,"%lf",&array[i]);
		printf("array[%d]=%lf ",i,array[i]);
		i++;
	}
	if(a>=b){
		return -1;
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
		if( fOfC>0 && fOfA>0){
			a=c;
		}
		else
			b=c;
	}
	printf("\nc=%f\n",c);
	//FILE *solver=fopen("part2_solver.dat","w");
	//output c to file solver
	return 0;
}
void app2(){
	
}

void app3(){

}

/*
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
}*/
