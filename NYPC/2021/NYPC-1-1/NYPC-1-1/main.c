#include<stdio.h>
#include<stdlib.h>

int main(void) {
    unsigned int n = 0;
    if (scanf("%d", &n)) {
        //입력
        int* arr = malloc(sizeof(int) * n);
        for (size_t i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        //처리
        long long int sum = arr[0];
        long long int sum_end = arr[0];
        for (size_t i = 1; i < n; i++) {
            sum_end += arr[i];
            if (sum_end < arr[i]) {
                sum_end = arr[i];
            }
            if (sum_end > sum) {
                sum = sum_end;
            }   
        }


        //출력
        printf("%lld", sum);
    }
}