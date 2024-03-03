//
//  stack.c
//  stack
//
//  Created by timoteosonurozcelik on 08/04/2023.
//

#include "stack.h"

int is_empty(struct node* top) {
    if(top == NULL){ 
        return 0;
    }   
    return 1;
}

void push(struct node** top, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
    newNode->value = value;

    if(*top == NULL){ 
        newNode->next = NULL;
        *top = newNode;
        return;
    }

    else{
        newNode->next = *top;
        *top = newNode;
    }
}

int pop(struct node** top) {
    if(*top == 0){
        return -1;
    }

    int data = (*top)->value;
    struct node* newNode = *top;
    *top = (*top)->next;

    free(newNode);
    return data ; 
}

int get_size(struct node* top) {
    int size = 0;
    if(top == 0){
        return 0;
    }
    struct node* check = top;
    while(check != NULL){
        size++;
        check = check->next;
    }
    return size;
}
