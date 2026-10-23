#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char value[255];
    struct Node *next;
} Node;


typedef struct Stack{
    Node *first;
    int total;
} Stack;

Node *createNode(const char *value);
void push(Stack *stack, Node *node);
Node *pop(Stack *stack);

void main(){
    Stack stack = {.first = NULL, .total = 0};

    push(&stack, createNode("Teste 1"));
    push(&stack, createNode("Teste 2"));
    push(&stack, createNode("Teste 3"));

    Node *n1 = pop(&stack);
    Node *n2 = pop(&stack);
    Node *n3 = pop(&stack);
    pop(&stack);
    
    printf("%s\n", n1->value);
    printf("%s\n", n2->value);
    printf("%s\n", n3->value);
}

Node *createNode(const char *value){
    Node *node = malloc(sizeof(Node));
    strcpy(node->value, value);
    node->next = NULL;
    return node;
}

void push(Stack *stack, Node *node){
    if(stack->total == 0){
        stack->first = node;
        stack->total++;
        return;
    }

    node->next = stack->first;
    stack->first = node;
    stack->total++;
    return;
}

Node *pop(Stack *stack){
    Node *node = malloc(sizeof(Node));

    if(stack->total == 0) return node;

    node = stack->first;
    stack->first = node->next;
    stack->total--;

    return node;
}
