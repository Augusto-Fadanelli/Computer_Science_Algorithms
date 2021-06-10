#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "multiplytbi.h"

int main()
{
    int tamA = 2;
    char numA[tamA];
    strcpy(numA, "98");

    int tamB = 2;
    char numB[tamB];
    strcpy(numB, "11");

    printf("mtbi: %d\n", mtbi(numA, numB, tamA, tamB));


    //struct timeb start, end;
    //int diff;


    return 0;
}
