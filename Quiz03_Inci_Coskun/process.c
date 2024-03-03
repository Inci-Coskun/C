//
//  process.c
//
//

#include "process.h"
#include <assert.h>

//kuyruğun sonuna eleman ekleme
void enqueue(struct process_queue** head, struct process proc) {    
    struct process_queue* new = (struct process_queue*)malloc(sizeof(struct process_queue));
    new->process = proc;
    new->next = NULL;
    if(new == NULL) {
        return;
    }
    if(*head == NULL) {
        *head = new;
        return;
    }
    struct process_queue* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

//kuyruğun başından eleman silme; process çekilip işlendikten sonra işlem süresi kalmadıysa.
void dequeue_and_pop(struct process_queue** head) { 
    if(*head == NULL) {
        return;
    }
    struct process_queue* temp = *head;
    *head = (*head)->next;
    free(temp);
}

//kuyruğun başına eleman ekleme
void push(struct process_queue** top, struct process proc) {
    struct process_queue* new = (struct process_queue*)malloc(sizeof(struct process_queue));
    new->process = proc;
    new->next = NULL;
    if(*top == NULL) {
        *top = new;
        return;
    }
    new->next = *top;
    *top = new;
}

//kuyruğun başındaki elemanı çekme; free işlemi yok
struct process_queue* peek(struct process_queue* head) {
    if(head == NULL) {
        return NULL;
    }
    return head;
}

int is_empty(struct process_queue* head) {
    if(head == NULL) {
        return 0;
    }
    return 1;
}

//kuyruğun başındaki elemanı sona atma; standart process çekilip işlendikten sonra süresi kaldıysa.
void round_queue(struct process_queue** head) {
    if(*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct process_queue* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    enqueue(head, temp->process);
    free(temp);
}

void print_queue(struct process_queue* head) {
    if(head == NULL) {
        printf("Process Queue is empty \n");
    }
    while(head != NULL) {
        printf("Process PID: %d -> ", head->process.PID);
        head = head->next;
    }
    printf("NULL \n");
}
