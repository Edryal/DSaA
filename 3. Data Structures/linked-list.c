#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void iterate_list(node_t *head);
void push_start(node_t **head, int data);
void push_end(node_t *head, int data);
void pop_first(node_t **head);
void pop_last(node_t *head);
void pop_index(node_t **head, int index);

int main() {
    node_t *head = NULL; 
    head = (node_t *) malloc(sizeof(node_t));

    head -> data = 10;
    head -> next = (node_t *) malloc(sizeof(node_t));

    head -> next -> data = 20;
    head -> next -> next = NULL;

    printf("List: ");
    iterate_list(head);

    push_end(head, 30);
    push_end(head, 15);
    push_start(&head, 1);
    printf("\nAfter push: ");
    iterate_list(head);

    pop_index(&head, 3);
    printf("\nPop index 3: ");
    iterate_list(head);

    pop_first(&head);
    printf("\nPop first: ");
    iterate_list(head);

    pop_last(head);
    printf("\nPop last: ");
    iterate_list(head);

    printf("\n");
    return 0;
}

void iterate_list(node_t *head) {
    node_t *iterate = head;

    while (iterate != NULL) {
        printf("%d ", iterate -> data);
        iterate = iterate -> next;
    }
}

void push_start(node_t **head, int data) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    new_node -> data = data;
    new_node -> next = *head;
    *head = new_node;
}

void push_end(node_t *head, int data) {
    node_t *iterate = head;

    while (iterate -> next != NULL) {
        iterate = iterate -> next;
    }

    iterate -> next = (node_t *) malloc(sizeof(node_t));
    iterate -> next -> data = data;
    iterate -> next -> next = NULL;
}

void pop_first(node_t **head) {
    node_t *next_node = (*head) -> next;
    free(*head);
    *head = next_node;
}

void pop_last(node_t *head) {
    if (head -> next == NULL) {
        free(head);
    }

    node_t *iterate = head;
    while (iterate -> next -> next != NULL) {
        iterate = iterate -> next; 
    }

    free(iterate -> next);
    iterate -> next = NULL;
}

void pop_index(node_t **head, int index) {
    node_t *iterate = *head;
    node_t *temp_node = NULL;

    if (index == 0) {
        pop_first(head);
    }

    for (int i = 0; i < index - 1; i++) {
        if (iterate -> next == NULL) {
            return;
        }
        iterate = iterate -> next;
    }

    if (iterate -> next == NULL) {
        free(iterate -> next);
        iterate -> next = NULL;
    }
    else {
        temp_node = iterate -> next;
        iterate -> next = temp_node -> next;
        free(temp_node);
    }
}
