#include <stdio.h>
#include <stdlib.h>

/*
#ifndef max
#define max(a, b) (((a)>(b)) ? (a):(b))
#endif
*/

int answers[31][1001] = {0};
int d[31];
int v[31];

int getMostGold(int timeLeft, int numThings, int w);
int myMax(int a, int b){

	return (a > b) ? a:b;
}

int main(int argc, char const *argv[])
{
	int i, j, airTime, wConstant, numTreasures;
	for (i = 1; i < 1001; ++i)
	{
		for (j = 1; j < 31; ++j)
		{
			answers[j][i] = -1;
		}
	}

	scanf("%d%d", &airTime, &wConstant);
	scanf("%d", &numTreasures);

	for (i = 0; i < numTreasures; ++i)
	{
		scanf("%d%d", &d[i + 1], &v[i + 1]);
	}
	printf("%d\n", getMostGold(airTime, numTreasures, wConstant));
	return 0;
}

int getMostGold(int timeLeft, int numThings, int w){
	int factor = w * 3;

	printf("\nTime left: %d  numThing: %d  w: %d\n", timeLeft, numThings, w);

	if (numThings < 0 || timeLeft < 0)
	{
		printf("Checking 1\n");
		return 0;
	}
	else if (answers[numThings][timeLeft] != -1)
	{
		printf("Checking 2\n");
		printf("Returning: %d\n", answers[numThings][timeLeft]);
		return answers[numThings][timeLeft];
	}
	else{
		printf("Checking 3\n");
		return answers[numThings][timeLeft] = myMax(v[numThings] + getMostGold(timeLeft - (d[numThings] * factor), numThings - 1, w), getMostGold(timeLeft, numThings - 1, w));
	}
}