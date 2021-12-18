#include<stdio.h>
#include<stdlib.h>

//not counted
#define NC -1
//calculated nums count
#define CNC 1000000

typedef struct F_0_1 {
    int f0;
    int f1;
}F_0_1;

F_0_1 calculated_nums[CNC];

F_0_1 fibonacci(int n);

int main(void) {
    F_0_1 default_val = { .f0 = NC, .f1 = NC };
    for (int i = 0; i < CNC; i++)
    {
        calculated_nums[i] = default_val;
    }
    int t = 0;
    scanf("%d", &t);
    int* inputs = (int*)malloc(sizeof(int) * t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &inputs[i]);
    }
    for (int i = 0; i < t; i++) {
        F_0_1 result = fibonacci(inputs[i]);
        printf("%d %d\n", result.f0, result.f1);
    }
}

F_0_1 fibonacci(int n) {
    F_0_1 result;
    result.f0 = 0;
    result.f1 = 0;
    if (calculated_nums[n].f0 != NC && calculated_nums[n].f1 != NC) {
        return calculated_nums[n];
    }
    if (n == 0) {
        result.f0++;
    }
    else if (n == 1) {
        result.f1++;
    }
    else {
        F_0_1 f1 = fibonacci(n - 1);
        F_0_1 f2 = fibonacci(n - 2);
        result.f0 = f1.f0 + f2.f0;
        result.f1 = f1.f1 + f2.f1;
    }
    calculated_nums[n] = result;
    return result;
}