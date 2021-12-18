#include<stdio.h>

//Not a Number
#define NaN -1
//Not Calculated
#define NC 0

int get_count(int n);
int min(int a, int b);

int counted_nums[5000] = { NC };

int main(void) {
	int n = 0;
	scanf("%d", &n);
	printf("%d", get_count(n));
}

int get_count(int n) {
	if (counted_nums[n - 1] != NC) {
		return counted_nums[n - 1];
	}
	else {
		if (n > 5) {
			int f3 = get_count(n - 3);
			int f5 = get_count(n - 5);

			if (f3 == NaN && f5 == NaN) {
				counted_nums[n - 1] = NaN;
				return NaN;
			}
			else {
				counted_nums[n - 1] = min(f3, f5) + 1;
				return min(f3, f5) + 1;
			}
		}

		switch (n) {
		case 1: return NaN;
		case 2: return NaN;
		case 3: return 1;
		case 4: return NaN;
		case 5: return 1;
		}
	}
}

int min(int a, int b) {
	if (a == NaN) {
		return b;
	}
	else if (b == NaN) {
		return a;
	}
	else {
		if (a > b) {
			return b;
		}
		return a;
	}
}