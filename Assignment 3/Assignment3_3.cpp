#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
	
	printf("Vector and scalar addition\n");
	int a1[200];
	int s = 200;
	int a3[200];
	omp_set_num_threads(8);
	for(int i=0; i<200; i++)
	{
		a1[i] = i;
	}
	int i;
	printf("\nStatic with chunk-size \n");
	#pragma omp parallel for shared (a1,s ,a3) private(i) schedule(static)
	for(i = 0; i < 200; i++)
	{
		a3[i] = a1[i] + s;
		#pragma omp critical
		printf("Thread Number: %d\n", omp_get_thread_num());
		printf("%3d  +  %3d   =   %3d\n",a1[i], s , a3[i]);
	}
	
}
