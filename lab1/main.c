/* main function for lab1 */
#include "lab1.h"

int main()
{
	printf("\nRAND_MAX = %d\n", RAND_MAX);

	random_char(200000);

	int coin_result = coin_toss(500);
	printf("Difference between heads and tails: %d\n", coin_result);

	int i=100;
	float diff,epsilon=0.0001;
	printf("	runs	difference\n");
	while(1){
		diff = (float) coin_toss(i)/(i/2);
		printf("%11d %10.7f\n",i, diff);
		if(diff < epsilon){
			break;
		}
		i+=i*2;
	}

	return 0;
}
