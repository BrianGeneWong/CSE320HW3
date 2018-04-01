#include <stdio.h>
#include <errno.h> 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

int main(int arc, char** argv){
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
	return 0;

}
