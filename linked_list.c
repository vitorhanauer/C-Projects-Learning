#include <stdio.h>

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


void main(){
    LinkedList list;
    Node node1 = {.value = 10, .next = NULL};
    Node node2 = {.value = 20, .next = NULL};
    Node node3 = {.value = 30, .next = NULL};
    Node node4 = {.value = 40, .next = NULL};

    insertInto(&list, &node1, 0);
    printf("%d\n", list.first->value);

    insertInto(&list, &node2, 1);
    printf("%d\n", list.last->value);

    insertInto(&list, &node3, 0);
    printf("%d\n", list.first->value);

    insertInto(&list, &node4, 1);
    printf("%d\n", list.first->next->value);

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