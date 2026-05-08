#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("1WA24CS223\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m];
    int max[n][m];
    int need[n][m];
    int available[m];
    int work[m];
    int finish[n];
    int safeSequence[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Demand Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int possible = 1;

                for(j = 0; j < m; j++) {

                    if(need[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {

                    for(k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    int safe = 1;

    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            safe = 0;
            break;
        }
    }

    if(safe) {
        printf("\nSystem is in a safe state.\n");

        printf("Safe sequence is: ");

        for(i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);

            if(i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else {
        printf("\nSystem is not in a safe state.\n");
    }

    return 0;
}

/*
OUTPUT
1WA24CS223
Enter number of processes: 5
Enter number of resources: 3

Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter Maximum Demand Matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter Available Resources:
3 3 2

System is in a safe state.
Safe sequence is: P1 -> P3 -> P4 -> P0 -> P2
*/
