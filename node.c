#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void addToEnd(Node **head, Student *student) {
    Node * addEnd = (Node *)malloc(sizeof(Node));
    addEnd->data = student;


    if ((*head == NULL)) {
        (*head) = addEnd;
    }
    else {
        Node * temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = addEnd;
        addEnd->prev = temp;
        addEnd->next = NULL;
    }
}


void addToStart(Node **head, Student *student) {
    Node * addNode = (Node *)malloc(sizeof(Node));
    addNode->data = student;
    addNode->next = (*head);
    addNode->prev = NULL;
    if ((*head) != NULL) {
        (*head)->prev = addNode;
    }
    (*head) = addNode;
}


void printList(Node *head) {
    if (!head == NULL) {
        Node * temp = head;
        while (temp->next != NULL) {
            Student * student = temp->data;
            printf("%s, %s\n", student->lName, student->fName);
            temp = temp->next;
        }
        Student *student = temp->data;
        printf("%s, %s\n", student->lName, student->fName);
    }
}


void removeByIndex(Node **head, int n) {
    if (*head == NULL) return;
    if (n < 0) return;
    if (n == 0) {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        return;
    }

    Node * temp = *head;\
        int i;
    for (i=0;temp != NULL && i<n;i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void removeLast(Node **head) {
    if ((*head) == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        return;
    }
    Node * temp = *head;

    while (temp->next != NULL) temp = temp->next;
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    free(temp);
}

void removeFirst(Node **head) {
    if (!(*head) == NULL) {


        Node * temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;

        free(temp);
    }
}