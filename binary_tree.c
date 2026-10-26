#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *childLeft;
    struct Node *childRight;
}Node;

Node *createNode(int value);

void main(){
    Node *node = createNode(10);
    printf("%d\n",node->value);
}

Node *createNode(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->childLeft = NULL;
    node->childRight = NULL;
    return node;
}