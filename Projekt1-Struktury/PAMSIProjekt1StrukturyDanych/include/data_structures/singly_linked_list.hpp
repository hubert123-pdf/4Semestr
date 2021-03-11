#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP

template <typename T>
class SinglyLinkedList
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
bool SinglyLinkedList<T>::empty()
{
    // TODO: zaimplementuj
    return false;
}

template <typename T>
std::size_t SinglyLinkedList<T>::size()
{
    // TODO: zaimplementuj
    return 0;
}

template <typename T>
void SinglyLinkedList<T>::addFront(const T& newElement)
{
    // TODO: zaimplementuj
}

template <typename T>
void SinglyLinkedList<T>::removeFront()
{
    // TODO: zaimplementuj
}

template <typename T>
void SinglyLinkedList<T>::addBack(const T& newElement)
{
    // TODO: zaimplementuj
}

template <typename T>
void SinglyLinkedList<T>::removeBack()
{
    // TODO: zaimplementuj
}

template <typename T>
const T& SinglyLinkedList<T>::front() const
{
    // TODO: zaimplementuj
    static T t;
    return t;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const
{
    // TODO: zaimplementuj
    static T t;
    return t;
}

template <typename T>
void SinglyLinkedList<T>::insert(const T& newElement, int index)
{
    // TODO: zaimplementuj
}

template <typename T>
void SinglyLinkedList<T>::remove(const T& element)
{
    // TODO: zaimplementuj
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int index)
{
    // TODO: zaimplementuj
    static T t;
    return t;
}
#endif // DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP
