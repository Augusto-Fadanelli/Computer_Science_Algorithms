#ifndef _MULTIPLYTBI_H
#define _MULTIPLYTBI_H

/*
* A multiplytbi.h se limita a usar apenas numeros inteiros positivos,
* sendo que o menor deles deve conter necessáriamente um número par de dígitos.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

//Function prototypes
void mtbi(const char *a, const char *b, const int numberOfDigitsA, const int numberOfDigitsB);
int mult(const short *vetA, const short *vetB, const int aL, const int aR, const int bL, const int bR, const int n);
//void split(unsigned long long int n, unsigned short *vetN, const int numberOfDigits);
//void dynamicAlloc(short *vetN, const short identifier);
int split(const char *vet, const int numberOfDigits, const char op);

void mtbi(const char *a, const char *b, const int numberOfDigitsA, const int numberOfDigitsB){

    //First number array
    short *vetA = NULL;
    vetA = (short*) malloc(numberOfDigitsA * sizeof(short)); //Memory allocation for vetA
    //Second number array
    short *vetB = NULL;
    vetB = (short*) malloc(numberOfDigitsB * sizeof(short)); //Memory allocation for vetB

    //int aL = atoi(a);
    //int aR = atoi(b);
    //printf("a: %d\nb: %d\n\n", teste1, teste2);

    int aL = split(a, numberOfDigitsA, 'L');
    int aR = split(a, numberOfDigitsA, 'R');

    printf("aL: %d\naR: %d\n\n", aL, aR);

    //split(a, vetA, numberOfDigitsA);
    //split(b, vetB, numberOfDigitsB);
    /*
    int aL = numberOfDigitsA/2;
    if(numberOfDigitsA%2 == 1){
        aL++;
    }
    int aR = numberOfDigitsA - aL;

    int bL = numberOfDigitsB/2;
    if(numberOfDigitsB%2 == 1){
        bL++;
    }
    int bR = numberOfDigitsB - bL;

    if(a/10 == 0 || b/10 == 0){ //if there's only one digit
        printf("Result: %d\n", a*b);
    }else{
        int n = numberOfDigitsA;
        if(numberOfDigitsA > numberOfDigitsB){
            n = numberOfDigitsB;
        }
        printf("Result: %d\n", mult(vetA, vetB, aL, aR, bL, bR, n));
    }

    //debug
    /*printf("aL: %d aR: %d\nbL: %d bR: %d\n\n", aL, aR, bL, bR);
    printf("First number: ");
    for(int i=0; i<numberOfDigitsA; i++){
        printf("%d, ", vetA[i]);
    }
    printf("\nSecond number: ");
    for(int i=0; i<numberOfDigitsB; i++){
        printf("%d, ", vetB[i]);
    }*/
}

int mult(const short *vetA, const short *vetB, int aL, int aR, int bL, int bR, const int n){

    int exponent = 0;

    int x = aL;
    aL = 0;
    for(int i=x-1; i>=0; i--){
        aL += pow(10, exponent) * vetA[i];
        //debug
        //printf("aL para i[%d]: %d\n", i, aL);
        exponent++;
    }
    aL++; //gambiarra
    exponent = 0;

    //debug
    //printf("\n---\naL: %d\n---\n\n", aL);

    int y = x + aR;
    aR = 0;
    for(int i=y-1; i>=x; i--){
        aR += pow(10, exponent) * vetA[i];
        //debug
        //printf("aR para i[%d]: %d\n", i, aR);
        exponent++;
    }
    exponent = 0;

    //debug
    //printf("\n---\naR: %d\n---\n\n", aR);

    x = bL;
    bL = 0;
    for(int i=x-1; i>=0; i--){
        bL += pow(10, exponent) * vetB[i];
        //debug
        //printf("bL para i[%d]: %d\n", i, bL);
        exponent++;
    }
    exponent = 0;

    //debug
    //printf("\n---\nbL: %d\n---\n\n", bL);

    y = x + bR;
    bR = 0;
    for(int i=y-1; i>=x; i--){
            bR += pow(10, exponent) * vetB[i];
            //debug
            //printf("bR para i[%d]: %d\n", i, bR);
        exponent++;
    }
    exponent = 0;

    //debug
    //printf("\n---\nbR: %d\n---\n\n", bR);

    int x1 = (aL * bL);
    int x2 = (aL * bR);
    int x3 = (aR * bL);
    int x4 = (aR * bR);

    return x1 * pow(10, n) + (x2 + x3) * pow(10, (n/2)) + x4;
}

//Split number into two parts
int split(const char *vet, const int numberOfDigits, const char op){

    int size_L = numberOfDigits/2;
    if(numberOfDigits%2 == 1){
        size_L++;
    }
    int size_R = numberOfDigits - size_L;

    int x = 0;
    int exponent = 0;
    if(op == 'L'){
        for(int i=size_L-1; i>=0; i--){
            x += pow(10, exponent) * atoi(vet[i]);
            exponent++;
        }
    }else{
        for(int i=numberOfDigits-1; i>=size_L; i--){
            x += pow(10, exponent) * atoi(vet[i]);
            exponent++;
        }
    }

    return x;
}

//Split number into two parts
/*void split(unsigned long long int n, unsigned short *vetN, const int numberOfDigits){
    int i = numberOfDigits-1;
    //short flag = 0;
    while(n>0){
    /*if(flag > 3){
        dynamicAlloc(vetN, identifier);
        flag = 0;
    }
    flag++;*/
/*
    //printf("%d - ",n%10);
    vetN[i] = n%10;
    n= n/10;
    i--;
    }

    //return i; //Size of *vetN
}*/

/*void dynamicAlloc(short *vetN, const short identifier){
    static int cont[2] = {1, 1};
    cont[identifier]++;

    vetN = (short*) realloc(vetN, cont[identifier] *4 * sizeof(short));

    if(vetN == NULL){
        printf("Array *vetN cannot be allocated!\nIdentifier: %d\n", identifier);
        getchar();
        exit(0);
    }

    //debug
    printf("\n\ncont[%d] = %d\n\n", identifier, cont[identifier]);
}*/

#endif
