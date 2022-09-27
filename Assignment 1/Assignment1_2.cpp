#include<stdio.h>
#include<omp.h>
int main()
{
	int i,sum=0;
	int thread_sum[8];
	omp_set_num_threads(8);
	#pragma omp parallel 
	{
		int ID = omp_get_thread_num();
		thread_sum[ID] = 0;
		#pragma omp for
		for(i=1;i<=100;i++)
		{
			printf ("Square of %d is %d printed by thread %d\n", i, (i*i),ID);
			thread_sum[ID] += (i*i);
		}
	}
	for(i=0;i<8;i++)
	{
	sum += thread_sum[i];
	}
	printf("Sum = %d",sum);
	return 0;
}
