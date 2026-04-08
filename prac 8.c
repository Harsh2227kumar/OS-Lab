#include <stdio.h>

int main() {
    int n, i, j, choice;
    int bt[20], pr[20], at[20], wt[20], tat[20], pid[20];
    int rem_bt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter priority for process %d: ", i+1);
        scanf("%d", &pr[i]);
        rem_bt[i] = bt[i];
    }

    printf("Choose scheduling type:\n1. Non-Preemptive\n2. Preemptive\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1) { // Non-preemptive
        for(i = 0; i < n - 1; i++) {
            for(j = i + 1; j < n; j++) {
                if(pr[i] > pr[j]) {
                    int temp;
                    temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                    temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                    temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
                    temp = at[i]; at[i] = at[j]; at[j] = temp;
                }
            }
        }

        wt[0] = 0;
        for(i = 1; i < n; i++)
            wt[i] = wt[i-1] + bt[i-1] - at[i];

        for(i = 0; i < n; i++)
            tat[i] = wt[i] + bt[i];

    } else if(choice == 2) { // Preemptive (Priority)
        int completed = 0, t = 0;
        int min_pr, idx;
        int done[20] = {0};
        wt[20] = {0};

        while(completed != n) {
            min_pr = 9999;
            idx = -1;
            for(i = 0; i < n; i++) {
                if(at[i] <= t && rem_bt[i] > 0) {
                    if(pr[i] < min_pr) {
                        min_pr = pr[i];
                        idx = i;
                    }
                }
            }

            if(idx != -1) {
                rem_bt[idx]--;
                if(rem_bt[idx] == 0) {
                    completed++;
                    tat[idx] = t + 1 - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                }
            }
            t++;
        }
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    float avg_wt = 0, avg_tat = 0;
    printf("\nPID\tAT\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
