#include <stdio.h>

int main() {
    int n, i;
    int pid[20], at[20], bt[20], pr[20];
    int wt[20], tat[20], ct[20];
    int completed[20] = {0};
    int current_time = 0, completed_count = 0;
    int highest_priority, selected;
    float avg_wt = 0, avg_tat = 0;

    printf("1WA24CS223\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i+1);
        scanf("%d", &pr[i]);
    }

    while(completed_count < n) {
        highest_priority = 999;
        selected = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == 0) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    selected = i;
                }
            }
        }

        if(selected == -1) {
            current_time++;
        } else {
            ct[selected] = current_time + bt[selected];
            tat[selected] = ct[selected] - at[selected];
            wt[selected] = tat[selected] - bt[selected];

            current_time = ct[selected];
            completed[selected] = 1;
            completed_count++;

            avg_wt += wt[selected];
            avg_tat += tat[selected];
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

/*
OUTPUT

1WA24CS223
Enter number of processes: 5

P1 Arrival Time: 0
P1 Burst Time: 3
P1 Priority: 5

P2 Arrival Time: 2
P2 Burst Time: 2
P2 Priority: 3

P3 Arrival Time: 3
P3 Burst Time: 5
P3 Priority: 2

P4 Arrival Time: 4
P4 Burst Time: 4
P4 Priority: 4

P5 Arrival Time: 6
P5 Burst Time: 1
P5 Priority: 1

Process AT BT PR CT TAT WT
P1      0  3  5  3   3   0
P2      2  2  3 11   9   7
P3      3  5  2  8   5   0
P4      4  4  4 15  11   7
P5      6  1  1  9   3   2

Average Waiting Time = 3.20
Average Turnaround Time = 6.20
*/
