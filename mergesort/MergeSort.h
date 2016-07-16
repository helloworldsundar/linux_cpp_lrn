#ifndef MERGESORT_H

#define MERGESORT_H

#include <iostream>
#include <string>
#include <malloc.h>

#define PROBLEM_SIZE 10
#define ITERATE(x) for(int i=0; (i < x); i++)
#define ITERATE_(x,y) for(int i=x; (i < y); i++)


class MergeSort
{
private:
    int* elem;
    int n;
    bool bReadyToSort;
    // debug information
    int nMergeCalls;
    int nMergeSortCalls;
    int nCompares;
    int nElemAccess;
public:
    MergeSort (int n,int* data);
    void streamElem (int n,int* data);
    void clearState ();
    void updateState ();
    void sort ();
    void doMergeSort (int start,int end);
    void Merge (int start,int mid,int end);
    void displayState ();
    int data (int index);
};

#endif
