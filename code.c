#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

#define kernel_2d_memcpy_syscall 451

int main()
{
	int rows =5, cols =5;
	float src[5][5] = { { 1.0,2.0,3.0,4.0,5.0},
			{2.0,3.0,4.0,5.0,6.0},
			{3.0,4.0,5.0,6.0,7.0},
			{4.0,5.0,6.0,7.0,8.0},
			{5.0,6.0,7.0,8.0,9.0}
	};
	float dest[5][5];

	int a = syscall(kernel_2d_memcpy_syscall,src,dest,rows,cols);
	
	printf("\n");
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%f " ,dest[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}


