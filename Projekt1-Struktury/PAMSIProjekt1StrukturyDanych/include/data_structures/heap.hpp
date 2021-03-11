#ifndef DATA_STRUCTURES_HEAP_HPP
#define DATA_STRUCTURES_HEAP_HPP

template <typename T>
class Heap
{
  public:
    void insert(const T& newElement);
    void removeMax();
    std::size_t size();
    bool empty();
    T& operator[](int index);
};

template <typename T>
void Heap<T>::insert(const T& newElement)
{
    // TODO: zaimplementuj
}

template <typename T>
void Heap<T>::removeMax()
{
    // TODO: zaimplementuj
}

template <typename T>
std::size_t Heap<T>::size()
{
    // TODO: zaimplementuj
    return 0;
}

template <typename T>
bool Heap<T>::empty()
{
    // TODO: zaimplementuj
    return false;
}

template <typename T>
T& Heap<T>::operator[](int index)
{
    // TODO: zaimplementuj
    static T t;
    return t;
}

#endif // DATA_STRUCTURES_HEAP_HPP
