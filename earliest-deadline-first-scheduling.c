#include <stdio.h>
#include <limits.h>

typedef struct {
    int id;
    int burst;
    int deadline;
    int period;
    int remaining_burst;
    int next_deadline;
} Task;

int main() {
    int n, total_time;

    printf("1WA24CS223\n");
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    for (int i = 0; i < n; i++) {
        printf("Enter PID, Burst, Deadline, and Period for Task %d: ", i + 1);
        scanf("%d %d %d %d",
              &tasks[i].id,
              &tasks[i].burst,
              &tasks[i].deadline,
              &tasks[i].period);

        tasks[i].remaining_burst = 0;
        tasks[i].next_deadline = 0;
    }

    printf("Enter total scheduling time (ms): ");
    scanf("%d", &total_time);

    printf("\nScheduling occurs for %d ms\n\n", total_time);

    for (int t = 0; t < total_time; t++) {

        // Release new jobs
        for (int i = 0; i < n; i++) {
            if (t % tasks[i].period == 0) {
                tasks[i].remaining_burst = tasks[i].burst;
                tasks[i].next_deadline = t + tasks[i].deadline;
            }
        }

        int selected = -1;
        int min_deadline = INT_MAX;

        // Select task with earliest deadline
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_burst > 0) {
                if (tasks[i].next_deadline < min_deadline) {
                    min_deadline = tasks[i].next_deadline;
                    selected = i;
                }
                else if (tasks[i].next_deadline == min_deadline) {
                    if (selected == -1 || tasks[i].id < tasks[selected].id) {
                        selected = i;
                    }
                }
            }
        }

        if (selected == -1) {
            printf("%dms : CPU is idle.\n", t);
        } else {
            printf("%dms : Task %d is running.\n", t, tasks[selected].id);
            tasks[selected].remaining_burst--;
        }
    }

    return 0;
}

/*
OUTPUT
1WA24CS223
Enter number of tasks: 3

Task 1: 1 3 7 20
Task 2: 2 2 4 5
Task 3: 3 2 8 10

Enter total scheduling time: 20

Scheduling occurs for 20 ms

0ms : Task 2 is running.
1ms : Task 2 is running.
2ms : Task 1 is running.
3ms : Task 1 is running.
4ms : Task 1 is running.
5ms : Task 3 is running.
6ms : Task 3 is running.
7ms : Task 2 is running.
8ms : Task 2 is running.
9ms : CPU is idle.
10ms : Task 2 is running.
11ms : Task 2 is running.
12ms : Task 3 is running.
13ms : Task 3 is running.
14ms : CPU is idle.
15ms : Task 2 is running.
16ms : Task 2 is running.
17ms : CPU is idle.
18ms : CPU is idle.
19ms : CPU is idle.
*/
