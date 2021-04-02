#include <iostream>
#include "../include/algorithms/mergesort.h"
#include <cstdio>
#include <ctime>

int main(int argc, char* argv[])
{
    std::clock_t start;
    double duration;
    MergeSort<int> *merge[100];
    for(int i=0;i<100;i++)  merge[i]=new MergeSort<int>(500000);
    for(int i=0;i<100;i++)  merge[i]->setRandom();
    start = std::clock();
    for(int i=0;i<100;i++)  merge[i]->mergeSort(0,500000);
    duration = ( std::clock() - start ) /(double) CLOCKS_PER_SEC;
    std::cout<<duration;
}
