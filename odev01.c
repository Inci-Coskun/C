float dotP(float *a, float *b, int n);
float mean(float *a, int n);
float variance(float *a, int n, int mean);

#include <stdio.h>

int main(){

    int n = 0;
    int i = 0;
    float a[100], b[100];

    printf("Enter the lenght of the vectors\n>>> ");
    scanf("%d", &n);

    while(n < 1){
        printf("\nPlease enter a valid lenght\n>>> ");
        scanf("%d", &n); 
    }
    
    printf("\nPlease enter the first vector\n>>> ");
    for(i=0; i<n; i++){
        scanf("%f", &a[i]);
    }

    printf("\nPlease enter the second vector\n>>> ");
    for(i=0; i<n; i++){
        scanf("%f", &b[i]);
    }

    float meanA = mean(a,n);
    float meanB = mean(b,n);
    printf("\nDot product is %.2f", dotP(a,b,n));
    printf("\nMean of the first vector is %.2f", meanA);
    printf("\nMean of the second vector is %.2f", meanB);
    printf("\nVariance of the first vector is %.2f", variance(a, n, meanA));
    printf("\nVariance of the second vector is %.2f\n", variance(b, n, meanB));

    return 0;
}

float dotP(float *a, float *b, int n){
    float dot_product = 0;
    for (int i=0; i<n; i++){
        dot_product = dot_product + a[i] * b[i];
    }
    return dot_product;
}

float mean(float *a, int n){
    float sum = 0;
    for(int i=0; i<n; i++){
      sum = sum + a[i];  
    }
    return sum / n;
}

float variance(float *a, int n, int mean){
    for(int i=0; i<n; i++){
      a[i] = a[i] - mean;  
    }
    return dotP(a, a, n)/n;
}
