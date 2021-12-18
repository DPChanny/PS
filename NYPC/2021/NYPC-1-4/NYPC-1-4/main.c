#include<stdio.h>
#include<stdlib.h>

typedef struct User
{
    int startTime;
    int isEnd;
} User;

int main(void)
{
    int n;
    int m;

    if (scanf("%d %d", &n, &m))
    {
        User* users = malloc(sizeof(User) * n);
        for (int i = 0; i < n; i++)
        {
            users[i].isEnd = 1;
        }
        for (int i = 0; i < m; i++)
        {
            int userId;
            int time;
            int isEnd;
            if (scanf("%d %d %d", &time, &userId, &isEnd))
            {
                if (users[userId - 1].isEnd == isEnd)
                {
                    printf("no");
                    return 0;
                }
                if (isEnd)
                {
                    if (time - users[userId - 1].startTime < 60)
                    {
                        printf("no");
                        return 0;
                    }
                }
                else
                {
                    users[userId - 1].startTime = time;
                }
                users[userId - 1].isEnd = isEnd;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!users[i].isEnd)
            {
                printf("no");
                return 0;
            }
        }
        printf("yes");
    }
    return 0;
}