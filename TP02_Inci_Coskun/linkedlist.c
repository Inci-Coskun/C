//
//  linkedlist.c
//  linkedlist
//

#include "linkedlist.h"


void insert_element(struct node** head, int data) {
    struct node* cur = *head;
    if(cur == NULL){
        cur = malloc(sizeof(struct node));
        cur->data = data;
        cur->next = NULL;
        *head = cur;
    }
    
    else {
 
        struct node* nxt = (*head) -> next;
        struct node* tmp = malloc(sizeof(struct node)) ;
        tmp->data = data;

        if (data < (cur->data)){
            tmp->next = cur;
            *head = tmp;    
        }

        else {
            while (nxt != NULL){
                if((data >= cur->data) && (data < nxt->data)){
                    cur->next = tmp;
                    tmp->next = nxt;
                    return;
                }
                cur = nxt;
                nxt = nxt->next;
            }

            if (data >= cur->data){
                cur->next = tmp;
                tmp->next = NULL;
            }
        }
    }
}

void remove_element(struct node** head, int data) {
    struct node* cur = *head;
    if(cur == NULL){
        return;
    }

    else{
        if(cur->data == data){
            *head = cur->next;
            free(cur);
        }
        else{
            struct node* nxt = (*head)->next;
            while(nxt != NULL){
                if(nxt->data == data){
                    cur->next = nxt->next;
                    free(nxt);
                    return;
                }
                cur = nxt;
                nxt = nxt->next;
            }
        }
    }
}

int search_element(struct node* head, int data) {
    struct node* cur = head;
    int i = 0;
    while(cur != NULL){
        if(data == cur->data){
            return i;
        }
        cur = cur->next;
        i++;
    }
    return -1;
}

int get_length(struct node* head) {
    int lenght = 0;
    while(head != NULL){
        head = head->next;
        lenght++;
    }
    return lenght;
}

void reverse(struct node** head) {
    int lenght = get_length(*head);
    if((head==NULL) || (lenght==1)){
        return;
    }
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* cur = *head;

    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}


void print(struct node* head) {
    struct node* tmp = head;
    printf("Linked list: ");

    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
}
