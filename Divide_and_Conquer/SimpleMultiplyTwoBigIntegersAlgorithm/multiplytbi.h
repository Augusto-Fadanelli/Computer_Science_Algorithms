#ifndef _MULTIPLYTBI_H
#define _MULTIPLYTBI_H

/*
* A multiplytbi.h se limita a usar apenas numeros inteiros positivos,
* sendo que o menor deles deve conter necessáriamente um número par de dígitos.
*/

#include <stdio.h>
#include <math.h>

//Function prototypes
void mtbi(const char *a, const char *b, const int numberOfDigitsA, const int numberOfDigitsB);
unsigned long long int mult(const int numberOfDigitsA, const int numberOfDigitsB, const unsigned long long int aL, const unsigned long long int aR, const unsigned long long int bL, const unsigned long long int bR);
unsigned long long int split(const char *vet, const int numberOfDigits, const char op);

void mtbi(const char *a, const char *b, const int numberOfDigitsA, const int numberOfDigitsB){

    unsigned long long int aL = split(a, numberOfDigitsA, 'L');
    unsigned long long int aR = split(a, numberOfDigitsA, 'R');

    printf("aL: %d\naR: %d\n\n", aL, aR);

    unsigned long long int bL = split(b, numberOfDigitsB, 'L');
    unsigned long long int bR = split(b, numberOfDigitsB, 'R');

    printf("bL: %d\nbR: %d\n\n", bL, bR);

    //if(a/10 == 0 || b/10 == 0){ //if there's only one digit
        //printf("Result: %d\n", a*b);
    //}else{

        //int teste = x1 * pow(10, n) + (x2 + x3) * pow(10, (n/2)) + x4;
        printf("Result: %d\n", mult(numberOfDigitsA, numberOfDigitsB, aL, aR, bL, bR));
    //}

}

unsigned long long int mult(const int numberOfDigitsA, const int numberOfDigitsB, const unsigned long long int aL, const unsigned long long int aR, const unsigned long long int bL, const unsigned long long int bR){

    int n = numberOfDigitsA;
    if(numberOfDigitsA > numberOfDigitsB){
        n = numberOfDigitsB;
    }

    unsigned long long int x1 = (aL * bL);
    unsigned long long int x2 = (aL * bR);
    unsigned long long int x3 = (aR * bL);
    unsigned long long int x4 = (aR * bR);

    return x1 * pow(10, n) + (x2 + x3) * pow(10, (n/2)) + x4;
}

//Split number into two parts
unsigned long long int split(const char *vet, const int numberOfDigits, const char op){

    int size_L = numberOfDigits/2;
    if(numberOfDigits%2 == 1){
        size_L++;
    }
    int size_R = numberOfDigits - size_L;

    unsigned long long int x = 0;
    int exponent = 0;
    if(op == 'L'){
        for(int i=size_L-1; i>=0; i--){
            x += pow(10, exponent) * (vet[i] - '0');
            exponent++;
        }
    }else{
        for(int i=numberOfDigits-1; i>=size_L; i--){
            x += pow(10, exponent) * (vet[i] - '0');
            exponent++;
        }
    }

    return x;
}

#endif
