#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void clook(int *requests, int n, int head) {
    int totalSeek = 0;
    int current = head;
    int sortedRequests[n];

    for (int i = 0; i < n; i++) {
        sortedRequests[i] = requests[i];
    }

    bubbleSort(sortedRequests, n);

    printf("Sequence of disk access: ");

   
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (sortedRequests[i] >= head) {
            start = i;
            break;
        }
    }

   
    for (int i = start; i < n; i++) {
        totalSeek += abs(current - sortedRequests[i]);
        printf("%d ", sortedRequests[i]);
        current = sortedRequests[i];
    }

   
    totalSeek += abs(current - sortedRequests[0]);
    printf("%d ", sortedRequests[0]);
    current = sortedRequests[0];

    for (int i = 1; i < start; i++) {
        totalSeek += abs(current - sortedRequests[i]);
        printf("%d ", sortedRequests[i]);
        current = sortedRequests[i];
    }

    printf("\nTotal seek time = %d\n", totalSeek);
}

int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *requests = (int *)malloc(n * sizeof(int));

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    clook(requests, n, head);

    free(requests);
    return 0;
}
