#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int findClosest(int *requests, int n, int head) {
    int minDistance = INT_MAX;
    int index = -1;

    for (int i = 0; i < n; ++i) {
        if (!requests[i]) continue; 
        int distance = abs(head - requests[i]);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }
    return index;
}


void sstf(int *requests, int n, int head) {
    int totalSeek = 0;
    int current = head;
    printf("Sequence of disk access: ");

    for (int i = 0; i < n; ++i) {
        int closest = findClosest(requests, n, current);
        totalSeek += abs(current - requests[closest]);
        printf("%d ", requests[closest]);
        current = requests[closest];
        requests[closest] = 0; 
    }

    printf("\nTotal seek time = %d\n", totalSeek);
}

int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &requests[i]);
    }

    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    sstf(requests, n, head);

    free(requests);
    return 0;
}
