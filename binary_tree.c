#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Node{
    int value;
    struct Node *childLeft;
    struct Node *childRight;
}Node;

typedef struct BinaryTree{
    Node *root;
    int height;
    int nodeNumber;

}BinaryTree;

BinaryTree *createBinaryTree(Node *node);
Node *createNode(int value);

void main(){
    BinaryTree *binaryTree = createBinaryTree(createNode(10));
    printf("Root Value: \t\t%d\n",binaryTree->root->value);
    printf("Height Value: \t\t%d\n",binaryTree->height);
    printf("Number of Nodes Value: \t%d\n",binaryTree->nodeNumber);
}

BinaryTree *createBinaryTree(Node *node){
    BinaryTree *binaryTree = malloc(sizeof(BinaryTree));
    binaryTree->root = node;
    binaryTree->height = 0;
    binaryTree->nodeNumber = 1;
    return binaryTree;
}

Node *createNode(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->childLeft = NULL;
    node->childRight = NULL;
    return node;
}