#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>
#include <time.h>
#include <stdlib.h>

// quicksort

template <typename T>
class QuickSort
{
    std::vector<T> tab;
    T N;
public:
    void sort(T start,T end);
    T partition(T start,T end);
    QuickSort(size_t Capacity);
    std::vector<T> getTab();
    void setRandom(T n);
    void printTab();
    void setRandomLeft();
    void reverse();
};
template <typename T>
QuickSort<T>::QuickSort(size_t capacity)
{
    tab.resize(capacity);
}
template <typename T>
void QuickSort<T>::sort(T start, T end) {

    if(start<end)                   //situation similar to mergesort, function calls itself recursively until there's one element
    {
        T part=partition(start,end);  //dividing tab into partitions
        sort(start,part-1);      //sort  left half
        sort(part+1,end);       //sort right half
    }
}
template <typename T>
std::vector<T> QuickSort<T>::getTab()
{
    return tab;
}
template <typename T>
T QuickSort<T>::partition(T start, T end) {
    T pivot=tab[(start+end)/2];         //taking middle element
    T i=start-1;                        //index of the elements bigger then pivot
    for (T j=start; j<= end-1; j++){        //until all elements are checked
        if(tab[j]<pivot) {              //if element is smaller than pivot he is swapped to the left side
            i++;
            T k;
            k=tab[j];
            tab[j]=tab[i];
            tab[i]=k;
        }
    }
    //moving pivot back to the middle
    tab[end]=tab[i+1];
    tab[i+1]=pivot;
    //returning index of the pivot
    return  ++i;
}
template <typename T>
void QuickSort<T>::setRandom(T n)
{
    this->N=n;
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        tab[i]=std::rand()%1000;
    }
}
template <typename T>
void QuickSort<T>::setRandomLeft() {
    srand(time(NULL));
    for(int i=N+1;i<tab.size();i++)
        tab[i]=std::rand()%1000+1000;
}
template<typename T>
void QuickSort<T>::printTab(){
    for(auto &v:tab)
        std::cout<<v<<std::endl;
}
template <typename T>
void QuickSort<T>::reverse(){
        for(int i=0;i<tab.size()/2;i++)
        {
            T k=tab[i];
            tab[i]=tab[tab.size()-i];
            tab[tab.size()-i]=k;
        }
}
#endif //SORTING_ALGORITHMS_QUICKSORT_H
