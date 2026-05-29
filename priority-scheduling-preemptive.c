/*
Algorithm: Priority Preemptive Scheduling

1. Start.
2. Read the number of processes.
3. Input Arrival Time, Burst Time and Priority for each process.
4. Initialize Remaining Time = Burst Time for all processes.
5. Set current time to 0.
6. Find all processes that have arrived and are not completed.
7. Select the process with the highest priority
   (smaller priority number indicates higher priority).
8. Execute the selected process for one time unit.
9. Decrease its Remaining Time by 1.
10. If Remaining Time becomes 0:
    a) Calculate Completion Time (CT).
    b) Calculate Turnaround Time (TAT = CT - AT).
    c) Calculate Waiting Time (WT = TAT - BT).
    d) Mark the process as completed.
11. Repeat Steps 6 to 10 until all processes are completed.
12. Calculate average Waiting Time and Turnaround Time.
13. Display the scheduling table.
14. Stop.
    */

#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int pid[20], at[20], bt[20], pr[20];
    int rt[20], ct[20], tat[20], wt[20];
    int highest, pos;
    float avg_wt = 0, avg_tat = 0;

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

        rt[i] = bt[i];
    }

    while(completed < n) {
        highest = 999;
        pos = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < highest) {
                highest = pr[i];
                pos = i;
            }
        }

        if(pos == -1) {
            time++;
        } else {
            rt[pos]--;
            time++;

            if(rt[pos] == 0) {
                completed++;
                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];

                avg_wt += wt[pos];
                avg_tat += tat[pos];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

/*
OUTPUT
Enter number of processes: 5

P1 Arrival Time: 0
P1 Burst Time: 3
P1 Priority: 3

P2 Arrival Time: 1
P2 Burst Time: 4
P2 Priority: 2

P3 Arrival Time: 2
P3 Burst Time: 6
P3 Priority: 4

P4 Arrival Time: 3
P4 Burst Time: 4
P4 Priority: 6

P5 Arrival Time: 4
P5 Burst Time: 2
P5 Priority: 10

Process AT  BT  PR  CT  TAT WT
P1      0   3   3   7   7   4
P2      1   4   2   5   4   0
P3      2   6   4   13  11  5
P4      3   4   6   17  14  10
P5      4   2   10  19  15  13

Average Waiting Time = 6.40
Average Turnaround Time = 10.20
*/
