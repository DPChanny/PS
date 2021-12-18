#include<stdio.h>

int main(void)
{
    int m = 0;
    int f = 0;
    int n = 0;

    if (scanf("%d %d %d", &m, &f, &n))
    {
        int num = 0;

        if (n <= m - 1)
        {
            num = 1;
        }
        else
        {
            num = n / (m - 1);
            if (n % (m - 1) != 0) {
                num++;
            }
        }

        printf("%d", num);
    }

    return 0;
}