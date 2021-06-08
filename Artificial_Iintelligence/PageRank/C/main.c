#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>

#include "pagerank.h"

#define PAGES 4

int main()
{
    /*double f = 1; //Frequency
    double x = 1;
    f = x/3;*/
    //Pages:             A  B  C  D  E
    /*bool pageA[PAGES] = {0, 0, 1, 0, 0};
    bool pageB[PAGES] = {1, 0, 0, 1, 1};
    bool pageC[PAGES] = {1, 1, 0, 1, 1};
    bool pageD[PAGES] = {0, 1, 1, 0, 1};
    bool pageE[PAGES] = {1, 0, 1, 0, 0};*/
    bool pageA[PAGES] = {0, 1, 1, 1};
    bool pageB[PAGES] = {1, 0, 0, 1};
    bool pageC[PAGES] = {0, 0, 0, 1};
    bool pageD[PAGES] = {0, 1, 1, 0};

    bool **pages = malloc(PAGES * sizeof(bool *));
    pages[0] = pageA;
    pages[1] = pageB;
    pages[2] = pageC;
    pages[3] = pageD;
    //pages[4] = pageE;

    //Show arrays
    for(int i=0; i<PAGES; i++){
        for(int j=0; j<PAGES; j++){
            printf("%d ", pages[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double pr[PAGES];
    for(int i=0; i<PAGES*5; i++){

        for(int j=0; j<PAGES; j++){
            pr[j] = pagerank(pages, j, PAGES);
        }

        //Show arrays
        for(int j=0; j<PAGES; j++){
            printf("pr[%d] = %f\n", j, pr[j]);
        }
        printf("\n");
    }

    return 0;
}
