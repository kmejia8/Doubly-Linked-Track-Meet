/* Author: Karla Mejia
Doubly Linked List Project: Track Meet

This code is provided here solely for educational and portfolio purposes.  
No permission is granted to copy, modify, or redistribute this code.  

*/


#include <stdio.h>
#include <stdlib.h> // for malloc
#include <string.h> // allows for string functions

// allows for 100 characters in both school or name
#define LEN_SCHOOL 100
#define LEN_NAME 100


// struct for doubly linked list for each runner in meet, each node represents one runner
struct Runner {
    struct Runner *previous; // refers to previous runner
    struct Runner *next; // refers to next runner

    // defining lane, bib number, name, school, qualifier time, record, etc.
    int lane;
    int bib_num;
    char name[LEN_NAME];
    char school[LEN_SCHOOL];
    float qual_time;
    float record_time;
};

// function for adding runner to list
void insert_entry(struct Runner **head, struct Runner *previous_Runner, struct Runner *new_Runner) {
    // first checking if the list is empty, meaning no head is present
    if (*head == NULL) {
        // if so, makes new_runner the head while defining its previous and next
        *head = new_Runner;
        new_Runner->previous = NULL;
        new_Runner->next = NULL;
    } else {
        // checking if adding at the very beginning
        if (previous_Runner == NULL) {
            // places new runner at head
            new_Runner->next = *head;
            new_Runner->previous = NULL;

            // 'moves' previous head while redefining new head
            (*head)->previous = new_Runner;
            *head = new_Runner;
        } else {
            // adding new entry into list
            new_Runner->next = previous_Runner->next;
            new_Runner->previous = previous_Runner;
            
            // if not inserting at the end, we must update the node in front
            if (previous_Runner->next != NULL) {
                previous_Runner->next->previous = new_Runner;
            }

            // finally, establishing new runner's place in list
            previous_Runner->next = new_Runner;
        }
    }
}

// function for removing runner from list
void remove_entry(struct Runner **head, struct Runner *Runner_to_remove) {
    // for if runner is at the head
    if (*head == Runner_to_remove) { // 'slices' off original head
        *head = Runner_to_remove->next;
    }

    // redefining 'next' if there is one
    if (Runner_to_remove->next != NULL) {
        Runner_to_remove->next->previous = Runner_to_remove->previous;
    }

    // redefining 'previous' if there is one
    if (Runner_to_remove->previous != NULL) {
        Runner_to_remove->previous->next = Runner_to_remove->next;
    }

    // finally, releasing memory of runner just removed
    free(Runner_to_remove);
}

// function for printing the list
void print_entries(struct Runner *head) {
    // starting at the beginning of the list
    struct Runner *current_head = head;

    printf("**List of Current Runners**\n");

    while (current_head != NULL) {
        // printing all info about each runner currently in list
        printf("----------------------\n");
        printf("Lane: %d\n", current_head->lane);
        printf("Bib: %d\n", current_head->bib_num);
        printf("Name: %s\n", current_head->name);
        printf("School: %s\n", current_head->school);
        printf("Qualifier Time: %.2f\n", current_head->qual_time);
        printf("Personal Record: %.2f\n", current_head->record_time);
        printf("----------------------\n");

        // going to next runner in list
        current_head = current_head->next;
    }
    printf("**All Runners Printed**\n\n");
}

int main(void) {
    // starting off with an empty list
    struct Runner *head = NULL;

    // allocating memory for three runners
    struct Runner *runner1 = (struct Runner *)malloc(sizeof(struct Runner));
    struct Runner *runner2 = (struct Runner *)malloc(sizeof(struct Runner));
    struct Runner *runner3 = (struct Runner *)malloc(sizeof(struct Runner));

    // creating first runner
    runner1->lane = 1;
    runner1->bib_num = 123;
    strcpy(runner1->name, "Karla M.");
    strcpy(runner1->school, "GMU");
    runner1->qual_time = 10.01;
    runner1->record_time = 9.00;

    // creating second runner
    runner2->lane = 2;
    runner2->bib_num = 456;
    strcpy(runner2->name, "Cyrus S.");
    strcpy(runner2->school, "GMU");
    runner2->qual_time = 9.01;
    runner2->record_time = 8.00;

    // creating third runner
    runner3->lane = 3;
    runner3->bib_num = 789;
    strcpy(runner3->name, "John D.");
    strcpy(runner3->school, "VT");
    runner3->qual_time = 11.54;
    runner3->record_time = 10.50;

    // printing current list (should be empty)
    print_entries(head);

    // inserting first runner
    printf("Adding Runner:\n");
    insert_entry(&head, NULL, runner1);

    // printing current list (should only have 1 runner)
    print_entries(head);

    // inserts runner1 after runner2
    printf("Adding Runner:\n");
    insert_entry(&head, runner1, runner2);

    // printing current list (should only have 2 runners)
    print_entries(head);

    // inserts runner3 as new head
    printf("Adding Runner:\n");
    insert_entry(&head, NULL, runner3);

    // printing current list (should only have 3 runners)
    print_entries(head);

    // removing runner
    printf("Removing Runner:\n");
    remove_entry(&head, runner1);

    // printing current list (should only have 2 runners)
    print_entries(head);

    // removing runner
    printf("Removing Runner:\n");
    remove_entry(&head, runner2);

    // printing current list (should only have 1 runner)
    print_entries(head);

    // removing runner
    printf("Removing Runner:\n");
    remove_entry(&head, runner3);

    // printing current list (list should now be empty)
    print_entries(head);

    return 0;
}