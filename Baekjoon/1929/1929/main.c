#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int min;
	int max;

	scanf("%d %d", &min, &max);

	int* primeNums = (int*)malloc(sizeof(int) * max);
	int primeNumCount = 0;

	for (int i = 2; i < max + 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < primeNumCount && i >= primeNums[j] * primeNums[j]; j++)
		{
			if (!(i % primeNums[j])) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			primeNums[primeNumCount++] = i;
			if (i >= min) {
				printf("%d\n", i);
			}
		}
	}
}