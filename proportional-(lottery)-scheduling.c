#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
char name[5];
int tickets;
} Process;

int main() {
int n, total_tickets = 0;
float total_T = 0.0;

```
printf("1WA24CS223\n");
printf("Enter the number of Processes: ");
scanf("%d", &n);

Process p[n];

srand(time(NULL));

for (int i = 0; i < n; i++) {
    printf("\nProcess %d:\n", i + 1);
    sprintf(p[i].name, "P%d", i + 1);

    printf("Tickets: ");
    scanf("%d", &p[i].tickets);

    total_tickets += p[i].tickets;
    total_T += p[i].tickets;
}

printf("\n--- Proportional Share Scheduling ---\n");
printf("Enter the Time Period for scheduling: ");

int m;
scanf("%d", &m);

for (int i = 0; i < m; i++) {
    int winning_ticket = rand() % total_tickets + 1;

    int accumulated_tickets = 0;
    int winner_index;

    for (int j = 0; j < n; j++) {
        accumulated_tickets += p[j].tickets;

        if (winning_ticket <= accumulated_tickets) {
            winner_index = j;
            break;
        }
    }

    printf("Tickets picked: %d, Winner: %s\n", winning_ticket, p[winner_index].name);
}

for (int i = 0; i < n; i++) {
    printf("\nThe Process: %s gets %.2f%% of Processor Time.\n",
           p[i].name,
           ((p[i].tickets / total_T) * 100));
}

return 0;
```

}

/*
OUTPUT

1WA24CS223
Enter the number of Processes: 3

Process 1:
Tickets: 10

Process 2:
Tickets: 20

Process 3:
Tickets: 30

--- Proportional Share Scheduling ---
Enter the Time Period for scheduling: 5

Tickets picked: 43, Winner: P3
Tickets picked: 18, Winner: P2
Tickets picked: 39, Winner: P3
Tickets picked: 35, Winner: P3
Tickets picked: 24, Winner: P2

The Process: P1 gets 16.67% of Processor Time.
The Process: P2 gets 33.33% of Processor Time.
The Process: P3 gets 50.00% of Processor Time.
*/
