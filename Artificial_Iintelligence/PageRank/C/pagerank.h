#ifndef _PAGERANK_H
#define _PAGERANK_H

#include <stdio.h>
#include <stdlib.h>

#define P 4 //numPages

double pagerank(const bool **pages, const int whichPage, const int numPages){
    bool links[numPages];
    getLinks(pages, whichPage, numPages, links);

    //inicialize status page rank
    static double pr[P]; //PageRank

    //inicialize old status PageRank
    static double oldPR[P];
    static first = true;
    if(first){
        for(int i=0; i<numPages; i++){
            oldPR[i] = 1.0f;
        }
        first = false;
    }

    for(int i=0; i<numPages; i++){
        if(1 == links[i]){
            pr[whichPage] += oldPR[i]/(double)numberOfLinks(pages, i, numPages);
        }
    }

    pr[whichPage] = 0.15f + 0.85f * pr[whichPage];

    double valuePR = pr[whichPage];

    //Save old status PageRank
    static int cont = 0;
    cont++;
    if(cont == numPages){
        for(int i=0; i<numPages; i++){
            oldPR[i] = pr[i];
        }
        for(int i=0; i<numPages; i++){
            pr[i] = 0.0f;
        }
        cont = 0;
    }

    return valuePR;
}

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

int numberOfLinks(const bool **pages, const int whichPage, const int numPages){
    int numLinks = 0;
    for(int j=0; j<numPages; j++){
        if(1 == pages[whichPage][j]){
            numLinks++;
        }
    }
    return numLinks;
}

#endif
