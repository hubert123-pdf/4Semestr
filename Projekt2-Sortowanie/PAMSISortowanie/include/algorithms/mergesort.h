#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>
#include <time.h>
#include <stdlib.h>

template <typename T>
class MergeSort
{
    T N;
    std::vector< T >tab;
public:
    explicit MergeSort(size_t capacity);
    void merge(T start,T middle,T end);
    void setRandom(T N);
    void setRandomLeft();
    void printArray();
    void sort(T left,T right);
    void reverse();
};
template <typename T>
MergeSort<T>::MergeSort(size_t capacity)
{
    tab.resize(capacity);
}
template <typename T>
void MergeSort<T>::merge(T start,T middle,T end)
{
    T Lsize = middle - start+1;            //left half
    T Rsize = end - middle;                //right half
    T index=start;
    T left[Lsize];                         //array of left elements
    T right[Rsize];                        //array of right elements
    for(int i=0;i<Lsize ;i++)
        left[i]=tab[start+i];              //Initialization of the left side
    for(int i=0;i<Rsize ;i++)
        right[i]=tab[middle+i+1];           //Initialization of the right side
    T i=0;
    T j=0;
    while(i<Lsize && j<Rsize)               //until both sides are sorted
    {
        if(left[i]<=right[j]) {             //(sorting) if element is smaller he goes to the default tab
            tab[index] = left[i];
            i++;                            //we move to the next column of the left tab
        }
        else{
            tab[index]=right[j];
            j++;                            //we move to the next column of the right tab
        }
     index++;                               //we move to the next column of the default tab
    }
    while(i<Lsize)                          //if theres any left columns on the left side we set them in default tab
    {
        tab[index]=left[i];
        i++; index++;
    }
    while(j<Rsize)                          //similar situation
    {
        tab[index]=right[j];
        j++; index++;
    }
}
template <typename T>
void MergeSort<T>::sort(T left,T right) {
    if (left < right) {                         //until there's one element
        T middle = (left + right) / 2;
        sort(left, middle);                //breaking list into two halves by calling function recursivly, it's the first one
        sort(middle + 1, right);      //second one
        merge(left, middle, right);            //when both halves are divided we can merge them together to the default tab
    }
}
template <typename T>
void MergeSort<T>::setRandom(T N)
{
    this->N=N;
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        tab[i]=std::rand()%1000;
    }
}
template <typename T>
void MergeSort<T>::setRandomLeft() {
    srand(time(NULL));
    for(int i=N+1;i<tab.size();i++)
        tab[i]=std::rand()%1000+1000;
}
template <typename T>
void MergeSort<T>::printArray()
{
    for(typename std::vector<T>::iterator it=tab.begin(); it!=tab.end();it++ )
        std::cout<<*it<<std::endl;
}
template <typename T>
void MergeSort<T>::reverse(){
    for(int i=0;i<tab.size()/2;i++)
    {
        T k;
        k=tab[i];
        tab[i]=tab[tab.size()-i];
        tab[tab.size()-i]=k;
    }
}

#endif //SORTING_ALGORITHMS_MERGESORT_H
