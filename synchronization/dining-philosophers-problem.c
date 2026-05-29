/*
Algorithm: Dining Philosophers Problem

1. Start.
2. Create five philosophers and five forks.
3. Initialize a mutex for each fork.
4. Create a separate thread for each philosopher.
5. Each philosopher performs the following repeatedly:
      a) Think for some time.
      b) Pick up the two required forks.
      c) Eat for some time.
      d) Put down both forks.
6. Even numbered philosophers pick up the left fork first,
   then the right fork.
7. Odd numbered philosophers pick up the right fork first,
   then the left fork.
8. This alternate order prevents deadlock.
9. Continue the thinking and eating cycle.
10. Wait for all philosopher threads to finish.
11. Destroy all mutexes.
12. Stop.
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];
pthread_t philosophers[N];

void* philosopher(void* num)
{
    int id = *(int*)num;
    int left = id;
    int right = (id + 1) % N;

    while (1)
    {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        if (id % 2 == 0)
        {
            pthread_mutex_lock(&forks[left]);
            printf("Philosopher %d picked left fork %d\n", id, left);

            pthread_mutex_lock(&forks[right]);
            printf("Philosopher %d picked right fork %d\n", id, right);
        }
        else
        {
            pthread_mutex_lock(&forks[right]);
            printf("Philosopher %d picked right fork %d\n", id, right);

            pthread_mutex_lock(&forks[left]);
            printf("Philosopher %d picked left fork %d\n", id, left);
        }

        printf("Philosopher %d is eating.\n", id);
        sleep(2);

        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);

        printf("Philosopher %d put down forks %d and %d\n", id, left, right);
    }

    return NULL;
}

int main()
{
    int i;
    int ids[N];

    for (i = 0; i < N; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
        ids[i] = i;
    }

    for (i = 0; i < N; i++)
    {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    for (i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}

/*
OUTPUT
Philosopher 0 is thinking.
Philosopher 1 is thinking.
Philosopher 2 is thinking.
Philosopher 3 is thinking.
Philosopher 4 is thinking.

Philosopher 0 picked left fork 0
Philosopher 0 picked right fork 1
Philosopher 0 is eating.

Philosopher 2 picked left fork 2
Philosopher 2 picked right fork 3
Philosopher 2 is eating.

Philosopher 0 put down forks 0 and 1

Philosopher 1 picked right fork 2
Philosopher 1 picked left fork 1
Philosopher 1 is eating.

Philosopher 2 put down forks 2 and 3

Philosopher 3 picked right fork 4
Philosopher 3 picked left fork 3
Philosopher 3 is eating.

Philosopher 1 put down forks 1 and 2
Philosopher 3 put down forks 3 and 4

Philosopher 4 picked left fork 4
Philosopher 4 picked right fork 0
Philosopher 4 is eating.

Philosopher 4 put down forks 4 and 0

...
*/
