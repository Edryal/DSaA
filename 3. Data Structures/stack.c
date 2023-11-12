#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

bool empty();
bool full();
void push(int element);
void pop();
void peek();

int main() {
    peek();
    push(5);
    push(15);
    push(30);
    push(8);
    push(19);
    push(27);

    printf("\nStack is full: %s\n", full() ? "true" : "false");
    peek();

    pop();
    printf("\nStack is full: %s\n", full() ? "true" : "false");
    peek();
}

bool empty() {
    return top == -1;
}

bool full() {
    return top == SIZE - 1; 
}

void push(int element) {
    if (full()) {
        printf("Overflow while pushing %d.\n", element);
        return;
    }

    top++;
    stack[top] = element;
    printf("Pushed %d.\n", element);
}

void pop() {
    if (empty()) {
        printf("Underflow while popping.\n");
        return;
    }

    printf("Popped %d.\n", stack[top]);
    top--;
}

void peek() {
    if (empty())
        printf("Stack is empty.\n");
    else printf("Element at the top: %d\n", stack[top]);
}
