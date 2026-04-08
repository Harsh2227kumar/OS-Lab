#include <stdio.h>

int main() {
    int n, i, time = 0, done = 0;
    int bt[20], rt[20], at[20], ct[20];
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

    float wt = 0, tat = 0;

    for(i = 0; i < n; i++) {
        int t = ct[i] - at[i];
        int w = t - bt[i];
        tat += t;
        wt += w;
    }

    printf("Average Waiting Time = %f\n", wt / n);
    printf("Average Turnaround Time = %f\n", tat / n);

    return 0;
}
