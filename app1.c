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
int main(int argc, char** argv){
//	printf("app1 start \n");
	FILE *input;
	input=fopen(*(argv+1),"r");
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
                double fOfC=function(c,n,array);
		if(fOfC==0)
			break;
		if(((b-a)/2)<e)
			break;
		//if sign (f(c))=sign(f(a)) then  a<-c else b<- c
		double fOfA=function(a,n,array);
		if( fOfC*fOfA>0){
			a=c;
		}
		else
			b=c;
	}
	printf("%lf\n",c);
	FILE *solver=fopen("part2_solver.dat","w+");
	fprintf(solver,"%lf",c);
	fclose(solver);
	return 0;
}
