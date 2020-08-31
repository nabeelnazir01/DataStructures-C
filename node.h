typedef struct Node {
    void * data;
    struct Node * next;
    struct Node * prev;
} Node;

#ifndef NODE_H_
#define NODE_H_
#include "student.h"
#define NULL 0

/*
 Adds a new node to the end of the list
 */
void addToEnd(Node **head, Student *student);

/*
 Adds a new node to the beginning of the list
 */
void addToStart(Node **head, Student *student);

/*
 Prints all student names in the following format: lastName, firstName
 */
void printList(Node *head);

/*
 Removes a node by index
 */
void removeByIndex(Node **head, int n);

/*
 Removes the last node in the list
 */
void removeLast(Node **head);

/*
 Remove the first node in the list
 */
void removeFromStart(Node **head);

#endif /* NODE_H_ */