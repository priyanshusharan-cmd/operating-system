/*
Algorithm: Shortest Job First (SJF) Non-Preemptive Scheduling

1. Start.
2. Read the number of processes.
3. Input Arrival Time and Burst Time for each process.
4. Mark all processes as unfinished.
5. Set current time to 0.
6. Find all processes that have arrived and are unfinished.
7. Select the process with the shortest Burst Time.
8. Execute the selected process until completion.
9. Calculate:
   CT = Completion Time
   TAT = CT - AT
   WT = TAT - BT
10. Mark the process as finished.
11. Repeat Steps 6 to 10 until all processes are completed.
12. Display CT, TAT and WT for all processes.
13. Stop.
    */

#include <stdio.h>

int main()
{
    int n, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int finished[n];

    // Input
    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        finished[i] = 0;
    }

    int current_time = 0;
    int completed = 0;

    // Scheduling logic (SJF Non-Preemptive)
    while (completed < n)
    {
        int min_bt = 9999;
        int index = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= current_time && finished[i] == 0)
            {
                if (bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if (index == -1)
        {
            current_time++; // CPU idle
        }
        else
        {
            ct[index] = current_time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];

            current_time = ct[index];
            finished[index] = 1;
            completed++;
        }
    }

    // Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}


/*
OUTPUT
Enter number of processes: 4
Enter Arrival Time and Burst Time for P1: 0 7
Enter Arrival Time and Burst Time for P2: 8 3
Enter Arrival Time and Burst Time for P3: 3 4
Enter Arrival Time and Burst Time for P4: 5 6

Process AT      BT      CT      TAT     WT
P1      0       7       7       7       0
P2      8       3       14      6       3
P3      3       4       11      8       4
P4      5       6       20      15      9
*/
