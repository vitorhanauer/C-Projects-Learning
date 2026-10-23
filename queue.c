#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *prev;
} Node;

typedef struct Queue{
    Node *begin;
    Node *end;
    int total;
} Queue;

Node *createNode(int value);
void push(Queue *queue, Node *node);
Node *pop(Queue *queue);

void main(){
    Queue queue = {.begin = NULL, .end = NULL, .total = 0};
    push(&queue, createNode(10));
    push(&queue, createNode(20));
    push(&queue, createNode(30));

    Node *n1 = pop(&queue);
    Node *n2 = pop(&queue);
    Node *n3 = pop(&queue);
    pop(&queue);

    printf("%d\n", n1->value);
    printf("%d\n", n2->value);
    printf("%d\n", n3->value);
}

Node *createNode(int value){
    Node *node = malloc(sizeof(Node));
    node->prev = NULL;
    node->value = value;
    return node;
}

void push(Queue *queue, Node *node){
    if(queue->total == 0){
        queue->begin = node;
        queue->end = node;
        queue->total++;
        return;
    }

    queue->end->prev = node;
    queue->end = node;
    queue->total++;
}

Node *pop(Queue *queue){
    Node *node = createNode(0);

    if(queue->total == 0) return node;

    node = queue->begin;
    queue->begin = node->prev;
    queue->total--;

    return node;
}