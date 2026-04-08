#include <stdio.h>

int main() {
    int n, f, i, j, k, flag, page, faults = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter pages: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);
    int frames[f];
    for(i = 0; i < f; i++) frames[i] = -1;

    int front = 0;
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
        }
        printf("Frames after accessing page %d: ", pages[i]);
        for(k = 0; k < f; k++) {
            if(frames[k] != -1) printf("%d ", frames[k]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
