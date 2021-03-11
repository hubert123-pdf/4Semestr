#ifndef STACK_HPP_
#define STACK_HPP_

// TODO: zaimplementuj klasę Stack - stos z implementacją tablicową
template <typename T>
class Stack
{
  public:
    Stack();
    explicit Stack(std::size_t initialCapacity);
    void push(const T& newElement);
    T pop();
    bool empty();
    std::size_t size();
    const T& top();
};

template <typename T>
Stack<T>::Stack()
{
    // TODO: zaimplementuj
}

template <typename T>
Stack<T>::Stack(std::size_t initialCapacity)
{
    // TODO: zaimplementuj - parametr to początkowa wielkość tablicy
}

template <typename T>
void Stack<T>::push(const T& newElement)
{
  // TODO: zaimplementuj
}

template <typename T>
T Stack<T>::pop()
{
  // TODO: zaimplementuj
  return T();
}

template <typename T>
bool Stack<T>::empty()
{
    // TODO: zaimplementuj
    return false;
}

template <typename T>
std::size_t Stack<T>::size()
{
    // TODO: zaimplementuj
    return 0;
}

template <typename T>
const T& Stack<T>::top()
{
    // TODO: zaimplementuj
    static T t;
    return t;
}

#endif /* STACK_HPP_ */
