#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool empty();
bool full();
int size();
void enqueue(int element);
void dequeue();
void print_queue();

int main() {
    printf("queue is empty: %s\n", empty() ? "true" : "false");

    enqueue(10);
    enqueue(5);
    enqueue(15);
    enqueue(19);
    enqueue(29);
    enqueue(53);
    print_queue();
    printf("queue size: %d\n\n", size());

    printf("queue is empty: %s\n", empty() ? "true" : "false");
    printf("queue is full: %s\n\n", full() ? "true" : "false");

    dequeue();
    print_queue();
    printf("queue size: %d\n", size());
}

bool empty() {
    return (front == -1 && rear == -1);
}

bool full() {
    return (rear == SIZE - 1);
}

int size() {
    if (empty())
        return 0;
    else return rear - front + 1;
}

void enqueue(int element) {
    if (full())
        printf("Overflow while enqueuing %d.\n", element);
    else {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = element;
    }
}

void dequeue() {
    if (empty()) {
        printf("Overflow while dequeuing.\n");
        return;
    }

    queue[front] = 0;
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void print_queue() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        for (int i = front; i <= rear; i++)
           printf("%d ", queue[i]);
        printf("\n");
    }
}
