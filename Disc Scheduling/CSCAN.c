#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, sum = 0, n, temp;
    int drq[21]; // Ensure this can handle n+1 requests
    int head, size;
    int hloc; // location of head in array

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the elements in disc queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &drq[i]);
    }

    printf("Enter the position of head: ");
    scanf("%d", &head);

    printf("Enter the total disk size: ");
    scanf("%d", &size);

    drq[n] = head; // add head to the queue
    n = n + 1; // increase the size of the array

    // sort the elements in the array
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(drq[i] > drq[j]) {
                temp = drq[i];
                drq[i] = drq[j];
                drq[j] = temp;
            }
        }
    }

    // find the location of head in array
    for(i = 0; i < n; i++) {
        if(drq[i] == head) {
            hloc = i;
            break;
        }
    }

    printf("\nSeek sequence =>\n");

    // SCAN towards the end of the disk
    for(i = hloc; i < n; i++) {
        printf("%d -> ", drq[i]);
        sum += abs(drq[i] - head);
        head = drq[i];
    }

    // Jump to the beginning of the disk
    printf("%d -> ", size - 1);
    sum += abs((size - 1) - head);
    head = size - 1;

    printf("0 -> ");
    sum += head; // move to 0
    head = 0;

    // SCAN from the beginning to the head position
    for(i = 0; i < hloc; i++) {
        printf("%d -> ", drq[i]);
        sum += abs(drq[i] - head);
        head = drq[i];
    }

    printf("\n\nTotal number of seek operations = %d \n", sum);

    return 0;
}
