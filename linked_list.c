#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList{
    Node *first;
    Node *last;
    int total;  
} LinkedList;

void insertInto(LinkedList *list, Node *node, int position);
Node *createNode(int value);
Node get(LinkedList *list, int position);

void main(){
    LinkedList list;
    Node *node1 = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);
    Node *node4 = createNode(40);

    insertInto(&list, node1, 0);
    insertInto(&list, node2, 1);
    insertInto(&list, node3, 2);
    insertInto(&list, node4, 3);
    Node temp = get(&list, 2);
    printf("%d\n", temp.value);

    return;
}

void insertInto(LinkedList *list, Node *node, int position){
    if(list->total < position) return;

    if(list->total == 0){
        list->first = node;
        list->last = node;
        list->total++;
        return;
    }

    if(position == 0){
        node-> next = list->first;
        list->first = node;

        list->total++;
        return;
    }

    if(list->total == position){
        list->last->next = node;
        list->last = node;

        list->total++;
        return;
    }

    Node *temp = list->first;

    for (int i = 0; i <= position; i++)
    {
        if(i != position - 1){
            temp = temp->next;
            continue;
        }
        node->next = temp->next;
        temp->next = node;
        list->total++;
        return;
    }
    
}

Node get(LinkedList *list, int position){
    if(position >= list->total) return *(list->last);
    if(position <= 0) return *(list->first);
    
    Node *temp = list->first;
    for (int i = 0; i != position; i++)
    {
        temp = temp->next;
    }
    return *temp;
}

Node *createNode(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}
