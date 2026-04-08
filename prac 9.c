#include <stdio.h>

int main() {
    int n, i, time = 0, done = 0;
    int bt[20], rt[20], at[20], ct[20], tat[20], wt[20];
    int max, idx;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(done < n) {
        max = -1;
        idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] > max) {
                    max = rt[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            rt[idx]--;
            time++;

            if(rt[idx] == 0) {
                ct[idx] = time;
                done++;
            }
        } else {
            time++;
        }
    }

    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %f\n", total_wt / n);
    printf("Average Turnaround Time = %f\n", total_tat / n);

    return 0;
}