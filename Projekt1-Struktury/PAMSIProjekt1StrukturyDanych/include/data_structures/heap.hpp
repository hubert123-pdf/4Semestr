#ifndef DATA_STRUCTURES_HEAP_HPP
#define DATA_STRUCTURES_HEAP_HPP
#define SIZE 10
template <typename T>
class Heap
{
    size_t size_h;
    T *heap;
    T *pointer;
  public:
    Heap();
    void insert(const T& newElement);
    void removeMax();
    std::size_t size();
    bool empty();
    T& operator[](int index);
};

template <typename T>
Heap<T>::Heap()
{
    heap=new T[SIZE];
    size_h=0;
}
template <typename T>
void Heap<T>::insert(const T& newElement)
{
    T position,old_man;                             //position of the new element and his father
    position=size_h;                                //position's index is the index of free column in array
    old_man=(size_h-1)/2;                           //father's positions is declared as this equation
    while(position>0&&heap[old_man]<newElement)     //while new element is not a root and is bigger than his father
    {
            heap[position] = heap[old_man];         //if new Element is greater than his father, he is the new father
            position = old_man;                     //index is also switched
            old_man = (position - 1) / 2;           //father is now at the position of his son
    }
    heap[position]=newElement;
    size_h++;
}

template <typename T>
void Heap<T>::removeMax()
{
    T value,l_son,father;
    l_son=1;                        //index of the first left son
    father=0;                       //index of the first father
    value=heap[size_h-1];           //value of the last element;
    heap[0]=value;
    if(size_h!=0)
    {
        while(l_son<size_h)                                     //while son's index is smaller than size of an array
        {
            if(l_son+1<size_h&&heap[l_son+1]>heap[l_son])       //if right son exists and his value is greater than left son's, we switch son's
                l_son++;
            if(heap[father]>=heap[l_son])                              //if value of the last element is greater than his son he is in the right place
                break;
            heap[father]=heap[l_son];                           //switching father and son
            father=l_son;
            l_son=2*l_son+1;                                    //son is going to the lower level
        }
        size_h--;
    }
}
template <typename T>
std::size_t Heap<T>::size()
{
    // TODO: zaimplementuj
    return size_h;
}

template <typename T>
bool Heap<T>::empty()
{
    if(size_h==0)
        return true;
    else
        return false;
}

template <typename T>
T& Heap<T>::operator[](int index)
{
    // TODO: zaimplementuj
    static T t;
    t=heap[index-1];
    return t;
}

#endif // DATA_STRUCTURES_HEAP_HPP
