#include <stdio.h>

int main() {
    int n, tq;
    int bt[20], rt[20];
    int i, time = 0, remain, wait = 0, turn = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    i = 0;

    while(remain > 0) {
        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            remain--;
            turn += time;
            wait += time - bt[i];
        } else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if(i == n - 1)
            i = 0;
        else
            i++;
    }

    printf("Average Waiting Time = %f\n", (float)wait / n);
    printf("Average Turnaround Time = %f\n", (float)turn / n);

    return 0;
}
