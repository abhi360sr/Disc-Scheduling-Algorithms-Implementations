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


void look(int *requests, int n, int head, int direction) {
    int totalSeek = 0;
    int current = head;
    int sortedRequests[n];

    for (int i = 0; i < n; i++) {
        sortedRequests[i] = requests[i];
    }

    bubbleSort(sortedRequests, n);

    printf("Sequence of disk access: ");

    if (direction == 0) {  
        for (int i = n - 1; i >= 0; i--) {
            if (sortedRequests[i] <= head) {
                totalSeek += abs(current - sortedRequests[i]);
                printf("%d ", sortedRequests[i]);
                current = sortedRequests[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (sortedRequests[i] > head) {
                totalSeek += abs(current - sortedRequests[i]);
                printf("%d ", sortedRequests[i]);
                current = sortedRequests[i];
            }
        }
    } else {  
        for (int i = 0; i < n; i++) {
            if (sortedRequests[i] >= head) {
                totalSeek += abs(current - sortedRequests[i]);
                printf("%d ", sortedRequests[i]);
                current = sortedRequests[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (sortedRequests[i] < head) {
                totalSeek += abs(current - sortedRequests[i]);
                printf("%d ", sortedRequests[i]);
                current = sortedRequests[i];
            }
        }
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

    int head, direction;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the initial direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    look(requests, n, head, direction);

    free(requests);
    return 0;
}
