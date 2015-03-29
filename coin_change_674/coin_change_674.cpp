#include <iostream>
#include <cstdlib>
using namespace std;

int ways[5][7490];
int coins[5] = {1, 5, 10, 25, 50};

int F(int change, int index);

int main(int argc, char const *argv[])
{
	int change;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 7490; ++j)
		{
			ways[i][j] = -1;
		}
	}
	//Filling up first block of each thing with known val 1
	for (int i = 0; i < 5; ++i)
	{
		ways[i][0] = 1;
	}
	//Filling up known quantities (all for the lowest denomination)
	for (int i = 0; i < 7490; ++i)
	{
		ways[0][i] = 1;
	}

	while(cin >> change){
		cout << F(change, 4) << endl;	
	}
	
	return 0;
}

int F(int change, int index){
	if (index < 0 || change < 0)
	{
		return 0;
	}

	if (ways[index][change != -1])
	{
		return ways[index][change];
	}
	else{
		return ways[index][change] = F(change - coins[index], index) + F(change, index - 1);
	}
}