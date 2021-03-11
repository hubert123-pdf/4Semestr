#ifndef DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
#define DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP

template <typename T>
class DoublyLinkedList
{
  public:
    bool empty();
    std::size_t size();
    void addFront(const T& newElement);
    void removeFront();
    void addBack(const T& newElement);
    void removeBack();
    const T& front() const;
    const T& back() const;
    void insert(const T& newElement, int index);
    void remove(const T& element);
    T& operator[](int index);
};

template <typename T>
bool DoublyLinkedList<T>::empty()
{
    // TODO: zaimplementuj
    return false;
}

template <typename T>
std::size_t DoublyLinkedList<T>::size()
{
    // TODO: zaimplementuj
    return 0;
}
template <typename T>
void DoublyLinkedList<T>::addFront(const T& newElement)
{
    // TODO: zaimplementuj
}
template <typename T>
void DoublyLinkedList<T>::removeFront()
{
    // TODO: zaimplementuj
}
template <typename T>
void DoublyLinkedList<T>::addBack(const T& newElement)
{
    // TODO: zaimplementuj
}
template <typename T>
void DoublyLinkedList<T>::removeBack()
{
    // TODO: zaimplementuj
}
template <typename T>
const T& DoublyLinkedList<T>::front() const
{
    // TODO: zaimplementuj
    static T t;
    return t;
}
template <typename T>
const T& DoublyLinkedList<T>::back() const
{
    // TODO: zaimplementuj
    static T t;
    return t;
}
template <typename T>
void DoublyLinkedList<T>::insert(const T& newElement, int index)
{
    // TODO: zaimplementuj
}
template <typename T>
void DoublyLinkedList<T>::remove(const T& element)
{
    // TODO: zaimplementuj
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index)
{
    // TODO: zaimplementuj
    static T t;
    return t;
}

#endif // DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
