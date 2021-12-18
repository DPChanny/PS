#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	unsigned int n = 0;
	if (scanf("%u", &n))
	{
		//입력
		unsigned int* arr = malloc(sizeof(unsigned int) * n);
		for (size_t i = 0; i < n; i++)
		{
			scanf("%u", &arr[i]);
		}

		//평균값
		unsigned int sum = 0;
		for (size_t i = 0; i < n; i++)
		{
			sum += arr[i];
		}
		unsigned int aver = sum / n;

		unsigned int plus_num = sum % n;
		unsigned int zero_num = n - plus_num;

		//처리
		unsigned int money = 0;

		for (size_t i = 0; i < n; i++)
		{
			if (arr[i] < aver) {
				if (zero_num > 0) {
					zero_num--;
					money += aver - arr[i];
				}
				else {
					plus_num--;
					money += aver - arr[i] + 1;
				}
			}
			else if (arr[i] > aver + 1) {
				if (plus_num > 0) {
					plus_num--;
				}
				else {
					zero_num--;
				}
			}
			else {
				if (arr[i] == aver) {
					if (zero_num > 0) {
						zero_num--;
					}
					else {
						money++;
						plus_num--;
					}
				}
				else if (arr[i] == aver + 1) {

					if (plus_num > 0) {
						plus_num--;
					}
					else {
						zero_num--;
					}
				}
			}
		}

		printf("%u", money);
	}
}