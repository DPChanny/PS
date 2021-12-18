#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    unsigned int worker_num;
    unsigned int day_num;

    if (scanf("%u %u", &worker_num, &day_num))
    {
        //배열 동적 할당 및 입력 받기
        unsigned int* left_days_per_worker = malloc(sizeof(unsigned int) * worker_num);
        for (size_t i = 0; i < worker_num; i++)
        {
            scanf("%u", &left_days_per_worker[i]);
        }
        unsigned int* max_worker_num_per_day = malloc(sizeof(unsigned int) * day_num);
        for (size_t i = 0; i < day_num; i++)
        {
            scanf("%u", &max_worker_num_per_day[i]);
        }
        
        //처리
        for (size_t i = 0; i < day_num; i++)
        {
            printf("%u ", max_worker_num_per_day[i]);

            //excepted 배열 선언 및 초기화
            unsigned char* excepted = malloc(sizeof(unsigned char) * worker_num);
            for (size_t j = 0; j < worker_num; j++)
            {
                excepted[j] = 0;
            }

            for (size_t j = 0; j < max_worker_num_per_day[i]; j++)
            {
                unsigned int max_id = 0;
                unsigned char is_found = 0;
                for (size_t i = 0; i < worker_num; i++)
                {
                    if (excepted[i])
                    {
                        continue;
                    }
                    if (left_days_per_worker[i] >= left_days_per_worker[max_id])
                    {
                        is_found = 1;
                        max_id = i;
                    }
                }
                if (is_found)
                {
                    left_days_per_worker[max_id]--;
                    excepted[max_id] = 1;
                    printf("%u ", max_id + 1);
                }
            }

            free(excepted);

            printf("\n");
        }

        free(left_days_per_worker);
        free(max_worker_num_per_day);
    }
    return 0;
}