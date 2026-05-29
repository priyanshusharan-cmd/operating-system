/*
Algorithm: Round Robin Scheduling

1. Start.
2. Read the number of processes.
3. Input Arrival Time and Burst Time for each process.
4. Read the Time Quantum.
5. Initialize Remaining Time = Burst Time for all processes.
6. Insert all arrived processes into the ready queue.
7. Select the first process from the queue.
8. Execute the process for:
   a) Time Quantum, or
   b) Remaining Burst Time, whichever is smaller.
9. Update the current time.
10. Add newly arrived processes to the queue.
11. If the process is not completed:
    Add it back to the end of the queue.
12. If the process completes:
    Calculate Completion Time (CT).
13. Repeat until all processes complete.
14. Calculate:
    TAT = CT - AT
    WT = TAT - BT
15. Display CT, TAT and WT for all processes.
16. Stop.
    */

#include <stdio.h>

int main()
{
    int n, quantum, time = 0, completed = 0;
    int queue[100], front = 0, rear = 0;
    int visited[100] = {0};
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    // Initial queue fill
    for (int i = 0; i < n; i++)
    {
        if (at[i] <= time)
        {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    // Round Robin logic
    while (front < rear)
    {
        int i = queue[front++];

        int execute = (rt[i] > quantum) ? quantum : rt[i];
        rt[i] -= execute;
        time += execute;

        // Add newly arrived processes
        for (int j = 0; j < n; j++)
        {
            if (at[j] <= time && visited[j] == 0)
            {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // If process not finished, push back
        if (rt[i] > 0)
        {
            queue[rear++] = i;
        }
        else
        {
            ct[i] = time;
            completed++;
        }

        // Handle idle condition
        if (front == rear && completed < n)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[j] == 0)
                {
                    time = at[j];
                    queue[rear++] = j;
                    visited[j] = 1;
                    break;
                }
            }
        }
    }

    // Output
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

/*
OUTPUT
Enter number of processes: 5
Enter AT and BT for P1: 0 5
Enter AT and BT for P2: 1 3
Enter AT and BT for P3: 2 1
Enter AT and BT for P4: 3 2
Enter AT and BT for P5: 4 3
Enter Time Quantum: 2

ID      AT      BT      CT      TAT     WT
1       0       5       13      13      8
2       1       3       12      11      8
3       2       1       5       3       2
4       3       2       9       6       4
5       4       3       14      10      7
*/
