#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE* fp = fopen("input.txt", "w");
	double num = 0.05;
	while(num <= 300){
		fprintf(fp, "%.2lf\n", num);
		num += 0.05;
	}
	return 0;
}