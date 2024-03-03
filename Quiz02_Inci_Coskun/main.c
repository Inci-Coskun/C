//
//  main.c
//  stack
//
//  Created by timoteosonurozcelik on 08/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int power(int x){
    int temp = 1;
    if(x == 0){
        return 1;
    }

    else{
        for(int m=0; m<x; m++){
            temp *= 10 ;
        }
        return temp;
    }

}

int is_palindrome(int number){
    int comingNumber = number;
    struct node* top = NULL;
    int new = 0; //tersini tutmak icin
    int k = 0;
    int array[32] = {0};

    if(number == 0){
        return 1;
    }

    while(number){
        array[k] = number % 10;
        number /= 10;
        push(&top, array[k]);
        k++;
    }

    int size = get_size(top);
    for(int t = 0; t < size; t++){
        int temp = pop(&top)*power(t);
        new += temp;
    }

    if(new == comingNumber){
        return 1;
    }
    return 0;      
}

int main(int argc, const char * argv[]){
    int i = 0;
    int N = 3;
    int arr[] = {0, 123, 232};
    for(i=0; i<N; i++) {
        if(is_palindrome(arr[i])) {
            printf("%d is a palindrome number \n", arr[i]);
        } else {
            printf("%d is not a palindrome number \n", arr[i]);
        }
    }
    return 0;
}


