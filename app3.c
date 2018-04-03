#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

int main (int argc,char** argv){
	FILE* output;
	int n=atoi(*(argv+1));
	uint64_t final;
//	printf("n is %d\n",n);
//	fscanf(input,"%d",n);
	uint64_t array[n+1];
	if(n==0)
		final=0;
	else if(n==1)
		final=1;
		
	else{
		array[0]=0;
		array[1]=1;

		int i=2;
		while(i<=n){
			array[i]=array[i-1]+array[i-2];
			i++;
		}
		final=array[n];
	}
//	printf("array[n]= %lu\n", array[n]);
	char* outFile="part2_fib.dat";
	output=fopen(outFile,"w+");
	fprintf(output,"%lu",final);
	fclose(output);	
	return 0;
}

