/*
* Title: Assignment 2 - Student Registration System
* w/ Linked List, Ansi-sytle
* Course: CST8234 - C Language
* Term: Summer 2020
* Team:
* Student #1: <<< Justin Warkus-Fortin (Wark0025) >>>
* Student #2: <<< Nabeel Nazir (nazi0022) >>>
*
* Status:
* Requirement #1: {complete}
* Requirement #2: {complete}
* Requirement #3: {complete}
* Requirement #4: {complete}
* Requirement #5: {complete}
* Requirement #6: {complete}
* Requirement #7: {complete}
* Requirement #8: {complete}
* Requirement #9: {complete}
* Requirement #10:{complete}
* Requirement #11:{complete}
*/

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *head = NULL;
Student s1, s2, s3, s4, s5, s6, s7, s8, s9;
int main(int argc, const char * argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    puts("First, you will enter 3 students names that will be added to the start of the list");

    enterNames(1, 1, &s1);
    enterNames(2, 1, &s2);
    enterNames(3, 1, &s3);

    puts("Then, you will enter 3 students names that will be added to the end of the list");

    enterNames(1, 0, &s4);
    enterNames(2, 0, &s5);
    enterNames(3, 0, &s6);

    printList(head);

    puts("Then, you will remove the first 3 students in the list");

    removeFirst(&head);
    removeFirst(&head);
    removeFirst(&head);
    printList(head);

    puts("Then, you will remove the last 3 students in the list");

    removeLast(&head);
    removeLast(&head);
    removeLast(&head);

    puts("By now, your list shoud be empty, so you will enter 3 more students");

    enterNames(1, 1, &s7);
    enterNames(2, 1, &s8);
    enterNames(3, 1, &s9);
    printList(head);

    puts("Finally, you will delete the second student in the list only");
    removeByIndex(&head, 1);
    printList(head);
    return EXIT_SUCCESS;
}
void enterNames(int num, int choice, Student * stud) {
    printf("Please enter first name for student %d: ", num);
    scanf("%s", stud->fName);
    printf("Please enter last name for student %d: ", num);
    scanf("%s", stud->lName);
    if (&choice == 1)
        addToStart(&head, stud);
    else
        addToEnd(&head, stud);
}