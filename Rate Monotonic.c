#include <stdio.h>

//Máximo Común Divisor
int MCD(int x, int y)
{
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

//Mínimo Común Múltiplo
int MCM(int x, int y)
{
    return (x * y) / MCD(x, y);
}

void rateMonotonic(int n, int m, int c[], int p[], int result[n][m])
{
    //Initialize Configuration
    int progress[n];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = 0;
        }
        progress[i] = 0;
    }

    //Rate Monotonic
    int stop = 0;
    for (int j = 0; j < m && stop == 0; j++)
    {
        //Increase Progress and Check Error
        for (int i = 0; i < n; i++)
        {
            if (j % p[i] == 0)
            {
                //Check ERROR
                if (progress[i] > 0)
                {
                    result[n][j] = -1;
                    stop = 1;
                    break;
                }
                //Increase C in Progress
                progress[i] += c[i];
            }
        }
        //Simulate Execution
        for (int i = 0; i < n && stop == 0; i++)
        {
            if (progress[i] > 0)
            {
                result[i][j] = 1;
                progress[i]--;
                break;
            }
        }
    }
}

int main()
{
    int n = 2;

    int c[] = {3, 4};
    int p[] = {6, 9};

    //Calculate MCM
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        m = MCM(p[i], p[i + 1]);
    }

    //Calculate Rate Monotonic
    int result[n + 1][m];
    rateMonotonic(n, m, c, p, result);

    //Print Result
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", result[i][j]);
            if (j == m - 1)
            {
                printf("\n");
            }
        }
    }

    return 0;
}