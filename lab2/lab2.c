/* A lab for time and math */
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	clock_t start, end;
	int num_iterations = 100000000;
	/* clean up the screen for the results of this program */
	system("clear");

	/* Tell user the program is running. Please wait. */
	printf("Program is running ... \n\n");

	/* This is how to invoke a function in <math.h> */
	int i;
	double time_taken;
	start = clock();
	for(i=0; i<num_iterations; i++){
		pow(1000.5, 2222.2);
	}
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
	printf("CPU time to invoke pow()  %d times: %f\n",num_iterations, time_taken);

	start = clock();
	for(i=0; i<num_iterations; i++){
		sqrt(20000);
	}
	end = clock();
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
	printf("CPU time to invoke sqrt() %d times: %f\n",num_iterations, time_taken);

	return 0;
}
