#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "multiplytbi.h"

int main()
{
    int tamA = 5;
    char numA[tamA];
    strcpy(numA, "98993");

    int tamB = 3;
    char numB[tamB];
    strcpy(numB, "102");

    mtbi(numA, numB, tamA, tamB);



    //int x = 0;
    //int y = 0;

    //struct timeb start, end;
    //int diff;

   /* unsigned long long int aleatorio1;
    unsigned long long int aleatorio2;
    for (int i=1; i <= 9; i++){

        aleatorio1 = 0;
        aleatorio2 = 0;

        for(int j=1; j<=pow(2, i)/2; j++){
            aleatorio1 += pow(10, j-1) * ( rand() % 9 ); //first number
            aleatorio2 += pow(10, j-1) * ( rand() % 9 ); //second number
        }
        //x = aleatorio1;
        //y = aleatorio2;

        //debug
        printf("\na1: %d\na2: %d\n", aleatorio1, aleatorio2);
    }*/

    return 0;
}
