#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];

    printf("Enter Arrival Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    int t = 0;

    for(i = 0; i < n; i++)
    {
        if(t < at[i])
            t = at[i];

        ct[i] = t + bt[i];
        t = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

/*
OUTPUT

Enter number of processes: 4

Enter Arrival Time:
0
0
0
0

Enter Burst Time:
7
3
4
6

Process AT      BT      CT      TAT     WT
P1      0       7       7       7       0
P2      0       3       10      10      7
P3      0       4       14      14      10
P4      0       6       20      20      14
*/
