#ifndef QUEUE_HPP_
#define QUEUE_HPP_

// TODO: zaimplementuj klasę Queue - kolejka z implementacją tablicową cykliczną
template <typename T>
class Queue
{
  public:
    Queue();
    explicit Queue(std::size_t initialCapacity);
    void enqueue(const T& newElement);
    T dequeue();
    bool empty();
    std::size_t size();
    const T& front();
};

template <typename T>
Queue<T>::Queue()
{
    // TODO: zaimplementuj
}

template <typename T>
Queue<T>::Queue(std::size_t initialCapacity)
{
    // TODO: zaimplementuj
}

template <typename T>
void Queue<T>::enqueue(const T& newElement)
{
    // TODO: zaimplementuj
}

template <typename T>
T Queue<T>::dequeue()
{
    // TODO: zaimplementuj
    return T();
}

template <typename T>
bool Queue<T>::empty()
{
    // TODO: zaimplementuj
    return false;
}

template <typename T>
std::size_t Queue<T>::size()
{
    // TODO: zaimplementuj
    return 0;
}

template <typename T>
const T& Queue<T>::front()
{
    // TODO: zaimplementuj
    static T t;
    return t;
}

#endif /* QUEUE_HPP_ */
