#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>
#include <time.h>
#include <stdlib.h>

template <typename T>
class MergeSort
{
    T capacity;
    std::vector< T >tab;
public:
    explicit MergeSort(size_t capacity);
    void merge(T start,T middle,T end);
    void setRandom();
    void printArray();
    void mergeSort(T left,T right);
};
template <typename T>
MergeSort<T>::MergeSort(size_t capacity)
{
    this->capacity=capacity;
    tab.resize(capacity);
}
template <typename T>
void MergeSort<T>::merge(T start,T middle,T end)
{
    T Lsize = middle - start + 1;          //left half
    T Rsize = end - middle;                //right half


    T left[Lsize];                         //array of left elements
    T right[Rsize];                        //array of right elements
    for(int i=0;i<Lsize ;i++)
        left[i]=tab[start+i];              //Initialization of the left side
    for(int i=0;i<Rsize ;i++)
        right[i]=tab[middle+i+1];           //Initialization of the right side

    T i=0;
    T j=0;
    T k=start;
    while(i<Lsize && j<Rsize)               //until both sides are sorted
    {
        if(left[i]<=right[j]) {             //(sorting) if element is smaller he goes to the default tab
            tab[k] = left[i];
            i++;                            //we move to the next column of the left tab
        }
        else
        {
            tab[k]=right[j];
            j++;                            //we move to the next column of the right tab
        }
        k++;                                //we move to the next column of the default tab
    }
    while(i<Lsize)                          //if theres any left columns on the left side we set them in default tab
    {
        tab[k]=left[i];
        i++;
        k++;
    }
    while(j<Rsize)                          //similar situation
    {
        tab[k]=right[j];
        j++;
        k++;
    }
}
template <typename T>
void MergeSort<T>::mergeSort(T left,T right) {
    if (left < right) {                         //until there's one element
        T middle = (left + right) / 2;
        mergeSort(left, middle);                //breaking list into two halves by calling function recursivly, it's the first one
        mergeSort(middle + 1, right);      //second one
        merge(left, middle, right);            //when both halves are divided we can merge them together to the default tab
    }
}
template <typename T>
void MergeSort<T>::setRandom()
{
    srand(time(NULL));
    for(int i=0;i<capacity;i++)
    {
        tab[i]=std::rand()%100;
    }
}
template <typename T>
void MergeSort<T>::printArray()
{
    for(auto const& v:tab)
        std::cout<<v<<std::endl;
}
#endif //SORTING_ALGORITHMS_MERGESORT_H
