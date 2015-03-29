#include <stdio.h>

long long ways[10][30001];
int money[10] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000};

long long makeChange(int index, int change);

int main(void)
{
	int i, j;
	int change;
	int cents, a, b;
	char c;

	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 30001; ++j)
		{
			ways[i][j] = -1;
		}
	}

	for (i = 0; i < 30001; ++i)
	{
		ways[0][i] = 1;
	}

	for (i = 0; i < 10; ++i)
	{
		ways[0][i] = 1;
	}

	
	scanf("%d%c%d", &a, &c, &b);
	int k = 1;
	a *= 100;

	change = a + b;

	while(a != 0 || b != 0){
		cents = (int)(change * 100 + .5);
		if (k == 1)
		{
			printf("%6.2lf%17Ld\n", change/100.0, makeChange(9, change));
			k = 0;
		}
		else{
			printf("%6.2lf%17Ld\n", change/100.0, makeChange(9, change));
		}
		scanf("%d%c%d", &a, &c, &b);
		a *= 100;

		change = a + b;

	}

	return 0;
}

long long makeChange(int index, int change){
	if (change < 0 || index < 0)
	{
		return 0;
	}

	if (ways[index][change] != -1)
	{
		return ways[index][change];
	}
	return ways[index][change] = makeChange(index, change - money[index]) + makeChange(index - 1, change);

}