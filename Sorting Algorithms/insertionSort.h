#ifndef _INSERTIONSORT_H
#define _INSERTIONSORT_H

void insertionSort(int *vet, int n){

    int aux; //Variable used to exchange integers in vector positions
    int j;

    for(int i=0; i < n; i++){
        aux = vet[i];
        j = i-1;

        while(j>=0 && vet[j] > aux){ //Invert the logical operator to change the order (> ascending; < descending)
            vet[j+1] = vet[j];
            j--;
        }

        vet[j+1] = aux;
    }
}

#endif
