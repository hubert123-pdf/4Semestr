#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

// sortowanie przez kopcowanie

template <typename T>
class HeapSort
{
    std::vector<T> tab;
public:
    void sort(T start,T end);
    HeapSort(size_t Capacity);
    std::vector<T> getTab();
    void setRandom();
    void printTab();
    void maxHeap(T index,T size);
};
template <typename T>
HeapSort<T>::HeapSort(size_t capacity)
{
    tab.resize(capacity);
}
template <typename T>
void HeapSort<T>::sort(T start, T end) {
    //making maxHeap data structure from tab
    for(int i=(start+end/2)-1;i>=start;i--)
        maxHeap(i,end);
    //switching root element with the last element and deleting it
    //by making maxHeap without last element
    for(int i=end-1;i>start;i--)
    {
        T k;
        k=tab[i];
        tab[i]=tab[0];
        tab[0]=k;
        maxHeap(0,i);
    }
}
template <typename T>
std::vector<T> HeapSort<T>::getTab()
{
    return tab;
}
template <typename T>
void HeapSort<T>::setRandom()
{
    srand(time(NULL));
    for(int i=0;i<tab.size();i++)
    {
        tab[i]=std::rand()%100;
    }
}g
template<typename T>
void HeapSort<T>::printTab(){
    for(typename std::vector<T>::iterator it=tab.begin();it!=tab.end();it++)
        std::cout<<*it<<std::endl;
}
template<typename T>
void HeapSort<T>::maxHeap(T index,T size)       //making heap data structure
{
    T Max=index;
    T left=2*index+1;                       //because indexing array from 0
    T right=2*index+2;
    if(left<size && tab[Max]<tab[left]){
        Max=left;
    }
    if(right<size && tab[Max]<tab[right]){
        Max=right;
    }
    if(Max==left || Max==right)
    {
        T k;
        k=tab[Max];
        tab[Max]=tab[index];
        tab[index]=k;
        maxHeap(Max,size);
    }
}


#endif //SORTING_ALGORITHMS_HEAPSORT_H
