#include <stdio.h>
#include "bubbleSort.h"

#define SIZE 10

int main()
{

    int vet[SIZE] = {41,23,87,47,35,19,20,8,11,32};

    for(int i=0; i<SIZE; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    bubbleSort(vet, SIZE);

    for(int i=0; i<SIZE; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
