#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[100], max[100], need[100];
    int avail[20], finish[20], safe[20];

    printf("Enter allocation matrix:\n");
    for(i = 0; i < n * m; i++)
        scanf("%d", &alloc[i]);

    printf("Enter max matrix:\n");
    for(i = 0; i < n * m; i++)
        scanf("%d", &max[i]);

    printf("Enter available resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate need
    for(i = 0; i < n * m; i++)
        need[i] = max[i] - alloc[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int ok = 1;

                for(j = 0; j < m; j++) {
                    if(need[i * m + j] > avail[j]) {
                        ok = 0;
                        break;
                    }
                }

                if(ok) {
                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i * m + k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found) {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("Safe sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}
