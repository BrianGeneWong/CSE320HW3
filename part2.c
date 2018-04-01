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
void app2(){
	FILE* input;
	input=fopen("matrix.txt","r");
	int x,y;
	fscanf(input,"%d %d",&x,&y);
	int matrix1[x][y];
	//put the numbers in the matrix;
	int i,j;
	for (i=0;i<x;i++){
		for(j=0;j<y;j++){
			fscanf(input,"%d",&matrix1[i][j]);
		//	printf("matrix at [%d][%d] is %d \n",i,j,matrix1[i][j]);
		}
	}
	int a,b;
	fscanf(input,"%d %d",&a,&b);
	printf("a is %d and b is %d\n",a,b);
	int matrix2[a][b];
	for (i=0;i<a;i++){
		for(j=0;j<b;j++){
			fscanf(input,"%d",&matrix2[i][j]);
	//		printf("matrix at [%d][%d] is %d \n",i,j,matrix2[i][j]);
		}
	}

	//now we do matrix multiplication
	//WE WILL get a square product matrix
	int product[x][b];
	int sum;
	int temp;
	int c=0;
	for (i=0;i<x;i++){
		for( j=0;j<b;j++){
			sum=0;
			for(c=0;c<y;c++){
				temp=matrix1[i][c]*matrix2[c][j];
				sum+=temp;
			}
		//	printf("sum for [%d][%d] is %d \n",i,j,sum);	
				product[i][j]=sum;
		}
	}	

	int trace=0;
	for(i=0;i<x;i++){
		trace+=product[i][i];
	}	
	printf("trace is %d\n",trace);

}
void app3(){
	FILE* input;
	int n=93;
//	fscanf(input,"%d",n);
	uint64_t array[n+1];
	if(n==0)
		printf("0\n");
	if(n==1)
		printf("1\n");
		
	array[0]=0;
	array[1]=1;

	int i=2;
	while(i<=n){
		array[i]=array[i-1]+array[i-2];
		i++;
	}
	printf("array[n]= %lu\n", array[n]);
		

}


int main(){
	app2();
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
