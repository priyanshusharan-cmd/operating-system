#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int mutex = 1;
int empty = BUFFER_SIZE;
int full = 0;

int item = 0;

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void produce() {
    if (empty == 0) {
        printf("Buffer is full\n");
        return;
    }

    wait(&empty);
    wait(&mutex);

    item++;
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;

    printf("Producer has produced: item%d\n", item);

    signal(&mutex);
    signal(&full);
}

void consume() {
    if (full == 0) {
        printf("Buffer is empty\n");
        return;
    }

    wait(&full);
    wait(&mutex);

    int consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    printf("Consumer has consumed: item%d\n", consumed);

    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;

    printf("\n1WA24CS223");

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Producer\n2. Consumer\n3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/*
OUTPUT

1WA24CS223

Enter your choice:
1. Producer
2. Consumer
3. Exit
1
Producer has produced: item1

Enter your choice:
1. Producer
2. Consumer
3. Exit
1
Producer has produced: item2

Enter your choice:
1. Producer
2. Consumer
3. Exit
2
Consumer has consumed: item1

Enter your choice:
1. Producer
2. Consumer
3. Exit
2
Consumer has consumed: item2

Enter your choice:
1. Producer
2. Consumer
3. Exit
2
Buffer is empty

Enter your choice:
1. Producer
2. Consumer
3. Exit
3
*/
