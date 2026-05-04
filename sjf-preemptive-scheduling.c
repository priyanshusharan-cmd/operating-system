#include <stdio.h>

int main()
{
    int n, i;
    printf("1WA24CS223\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    int current_time = 0, completed = 0;

    while (completed < n)
    {
        int min_rt = 9999, index = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= current_time && rt[i] > 0)
            {
                if (rt[i] < min_rt)
                {
                    min_rt = rt[i];
                    index = i;
                }
            }
        }

        if (index == -1)
        {
            current_time++;
        }
        else
        {
            rt[index]--;
            current_time++;

            if (rt[index] == 0)
            {
                completed++;
                ct[index] = current_time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

/*
OUTPUT
1WA24CS223
Enter number of processes: 4
Enter Arrival Time and Burst Time for P1: 0 8
Enter Arrival Time and Burst Time for P2: 1 4
Enter Arrival Time and Burst Time for P3: 2 9
Enter Arrival Time and Burst Time for P4: 3 5

P	AT	BT	CT	TAT	WT
P1	0	8	17	17	9
P2	1	4	5	4	0
P3	2	9	26	24	15
P4	3	5	10	7	2
*/
