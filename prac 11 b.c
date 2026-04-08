#include <stdio.h>

int main() {
    int n, f, i, j, k, page, faults;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter pages: ");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frames[f], temp[f];
    for(i = 0; i < f; i++) frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");
    faults = 0;
    int front = 0;
    for(i = 0; i < n; i++) {
        int flag = 0;
        for(j = 0; j < f; j++) if(frames[j] == pages[i]) flag = 1;
        if(!flag) {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
        }
        printf("After page %d: ", pages[i]);
        for(k = 0; k < f; k++) {
            if(frames[k] != -1) printf("%d ", frames[k]);
            else printf("- ");
        }
        printf("\n");
    }
    printf("Total FIFO Page Faults = %d\n", faults);

    printf("\nLRU Page Replacement:\n");
    faults = 0;
    int time[f];
    for(i = 0; i < f; i++) frames[i] = -1, time[i] = 0;
    for(i = 0; i < n; i++) {
        int flag = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                time[j] = i;
            }
        }
        if(!flag) {
            int min = 0;
            for(j = 1; j < f; j++) if(time[j] < time[min]) min = j;
            frames[min] = pages[i];
            time[min] = i;
            faults++;
        }
        printf("After page %d: ", pages[i]);
        for(k = 0; k < f; k++) {
            if(frames[k] != -1) printf("%d ", frames[k]);
            else printf("- ");
        }
        printf("\n");
    }
    printf("Total LRU Page Faults = %d\n", faults);

    return 0;
}
