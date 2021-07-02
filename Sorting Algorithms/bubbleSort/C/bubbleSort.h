#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

#include <stdbool.h>

void bubbleSort(int *vet, int n){

    bool flag = false; //Checks if the values ​​are ordered and exits the loop
    int aux; //Used to exchange integers in vector positions

    do{
        flag = true;

        for(int i=0; i<n; i++){
            if(vet[i] > vet[i+1] && i != n-1){ //Invert the logical operator to change the order (> ascending; < descending)
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;

                flag = false;
            }
        }

    }while(flag == false);
}

#endif
