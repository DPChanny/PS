#include<stdio.h>
#include<stdlib.h>

int get_length(int* _list, int* _list_cal, int _n) {
	if (_list_cal[_n] == 0) {
		int max = 0;
		for (int i = 0; i < _n; i++)
		{
			if (_list[_n] > _list[i]) {
				int n = get_length(_list, _list_cal, i);
				if (n > max) {
					max = n;
				}
			}
		}

		_list_cal[_n] = max + 1;
	}

	return _list_cal[_n];
}

int main(void) {
	int n;
	scanf("%d", &n);
	int* list = (int*)malloc(sizeof(int) * n);
	int* list_cal = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int n = get_length(list, list_cal, i);
		if (n > max) {
			max = n;
		}
	}

	printf("%d", n - max);
}