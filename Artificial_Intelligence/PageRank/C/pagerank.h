#ifndef _PAGERANK_H
#define _PAGERANK_H

#include <stdio.h>

#define P 5 //numPages

double pagerank(const bool **pages, const int whichPage, const int numPages){

    bool links[numPages];
    getLinks(pages, whichPage, numPages, links);

    static double pr[P]; //PageRank
    static double oldPR[P]; //Old values of PageRank

    //If it's first loop
    static first = true;
    if(first){
        inicializeArray(oldPR, numPages, 1.0f);
        first = false;
    }

    //Calculate PageRank
    for(int i=0; i<numPages; i++){
        if(1 == links[i]){
            pr[whichPage] += oldPR[i]/(double)numberOfLinks(pages, i, numPages);
        }
    }
    pr[whichPage] = 0.15f + 0.85f * pr[whichPage]; //85 represents the probability in % that someone will click the link

    double valuePR = pr[whichPage];

    //Save old status PageRank
    static int cont = 0;
    cont++;
    if(cont == numPages){
        for(int i=0; i<numPages; i++){
            oldPR[i] = pr[i];
        }
        inicializeArray(pr, numPages, 0.0f);
        cont = 0;
    }

    return valuePR;
}

//Get links from other pages that point to the current page
void getLinks(const bool **pages, const int wichPage, const int numPages, bool *links){
    for(int i=0; i<numPages; i++){
        if(1 == pages[i][wichPage]){
            if(i == wichPage){
                links[i] = 0;
            }else{
                links[i] = 1;
            }
        }else{
            links[i] = 0;
        }
    }
}

//Count the number of links in page
int numberOfLinks(const bool **pages, const int whichPage, const int numPages){
    int numLinks = 0;
    for(int j=0; j<numPages; j++){
        if(1 == pages[whichPage][j]){
            numLinks++;
        }
    }
    return numLinks;
}

void inicializeArray(double *vet, int sizeOfArray, double value){
    for(int i=0; i<sizeOfArray; i++){
        vet[i] = value;
    }
}

#endif
