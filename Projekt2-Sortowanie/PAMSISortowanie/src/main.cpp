#include <iostream>
#include "../include/algorithms/mergesort.h"
#include "../include/algorithms/quicksort.h"
#include "../include/algorithms/heapsort.h"
#include <cstdio>
#include <ctime>

int main(int argc, char* argv[])
{
    std::clock_t start;
    double duration;

    MergeSort<int> *merge[100];
    for(int i=0;i<100;i++)  merge[i]=new MergeSort<int>(1000000);
    for(int i=0;i<100;i++)  merge[i]->setRandom(1000000);
    for(int i=0;i<100;i++)  merge[i]->sort(0,1000000);
    for(int i=0;i<100;i++)  merge[i]->setRandomLeft();
    start = std::clock();
    for(int i=0;i<100;i++)  merge[i]->sort(0,1000000);
    duration = ( std::clock() - start )/(double) CLOCKS_PER_SEC;
    std::cout<<duration;

  /*  QuickSort<int> *quick[100];
    for(int i=0;i<100;i++) quick[i]=new QuickSort<int>(500000);
    for(int i=0;i<100;i++) quick[i]->setRandom(500000);
    for(int i=0;i<100;i++) quick[i]->sort(0,500000);
    for(int i=0;i<100;i++) quick[i]->reverse();
    quick[0]->printTab();
    start = std::clock();
    for(int i=0;i<100;i++) quick[i]->sort(0,500000);
    duration = ( std::clock() - start ) /(double) CLOCKS_PER_SEC;
    std::cout<<duration;*/

   /*  HeapSort<int> *heap[100];
     for(int i=0;i<100;i++)  heap[i]=new HeapSort<int>(1000000);
     for(int i=0;i<100;i++)  heap[i]->setRandom(250000);
     for(int i=0;i<100;i++)  heap[i]->sort(0,250000);
    for(int i=0;i<100;i++)   heap[i]->setRandomLeft();
    start = std::clock();
     for(int i=0;i<100;i++)  heap[i]->sort(0,1000000);
     duration = ( std::clock() - start ) /(double) CLOCKS_PER_SEC;
     std::cout<<duration;*/
}
