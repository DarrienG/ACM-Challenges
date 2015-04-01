#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max (a, b) (((a) > (b)) ? (a):(b))
#endif

int answers[31][1001] = {0};
int d[30];
int v[30];

int getMostGold(int timeLeft, int numThings);

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
		scanf("%d%d", d[i], v[i]);
	}
	return 0;
}

int getMostGold(int timeLeft, int numThings){
	if (numThings < 0 || timeLeft < 0)
	{
		return 0;
	}
	else if (answers[numThings][timeLeft] != -1)
	{
		return answers[numThings][timeLeft];
	}
	else{
		return answers[numThings][timeLeft] = max(v[numThings] + getMostGold(timeLeft - d[numThings], numThings - 1)), getMostGold(timeLeft, numThings - 1);
	}
}