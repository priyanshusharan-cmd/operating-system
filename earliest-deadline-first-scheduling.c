/*
Algorithm: Earliest Deadline First (EDF) Scheduling

1. Start.
2. Read the number of tasks.
3. For each task, input:
      a) Process ID
      b) Burst Time
      c) Relative Deadline
      d) Period
4. Read the total scheduling time.
5. At every time unit:
      a) Release new task instances when the current time is a multiple of the task period.
      b) Assign a new absolute deadline to released tasks.
6. Among all ready tasks, select the task with the earliest deadline.
7. If two tasks have the same deadline, select the task with the smaller Process ID.
8. Execute the selected task for one time unit.
9. Decrease its remaining burst time.
10. If no task is ready, keep the CPU idle.
11. Repeat until the total scheduling time is completed.
12. Display the task executed at each time unit.
13. Stop.
*/

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

Enter number of tasks: 3

Enter PID, Burst, Deadline, and Period for Task 1: 1 3 7 20
Enter PID, Burst, Deadline, and Period for Task 2: 2 2 4 5
Enter PID, Burst, Deadline, and Period for Task 3: 3 2 8 10

Enter total scheduling time (ms): 20

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
