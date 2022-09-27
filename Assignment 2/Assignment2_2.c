#include <stdlib.h>   
#include <stdio.h>    
#include <omp.h>      

int main (int argc, char *argv[]) 
{
	int * a;
	int * b; 
	int * c;  
    int n = 8;                 // number of array elements
	int n_per_thread;                   // elements per thread
	int total_threads = 8;    // number of threads to use  
	int i;       
    a = (int *) malloc(sizeof(int)*n);
	b = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);

    for(i=0; i<n; i++) {
            a[i] = i*i;
            b[i] = i;    
        }
      
	omp_set_num_threads(total_threads);

	#pragma omp parallel for shared(a, b, c) private(i) schedule(static)
        for(i=0; i<n; i++) {
		c[i] = a[i]+b[i];
		printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
        }
	
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
        for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
        }
        free(a);  free(b); free(c);
	
	return 0;
}
