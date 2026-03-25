nano sjf.c

#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}



./a.out



Enter number of processes: 10\

pract

v13.3.0

./a.out

Theory-

the

Enter Burst Time for Process 1: Enter Burst Time for Process 2: Enter Burst Time for Process 3: Enter Bu rst Time for Process 4: Enter Burst Time for Process 5: Enter Burst Time for Process 6: Enter Burst Time for Process 7: Enter Burst Time for Process 8: Enter Burst Time for Process 9: Enter Burst Time for Pro

firs

cess 10:

Process Burst Time

Waiting Time

Turnaround Time

P5

-1

P6

-1

-1

-2

P2

-2

-2

-2

-2

P8

-2

-2

but

M

Steps te

@ Ope

P10

-2

-2

P3

8

-2

6

P9

12

6

18

P7

64

18

82

P1

8388690

S

8388668

82

Average Waiting Time = 9.50

Average Turnaround Time 838878.50