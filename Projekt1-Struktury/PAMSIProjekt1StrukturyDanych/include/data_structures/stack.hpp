#ifndef STACK_HPP_
#define STACK_HPP_
#define SIZE 10

// TODO: zaimplementuj klasę Stack - stos z implementacją tablicową
template <typename T>
class Stack
{
  private:
    T *pointer;
    T *stack;
    T numberOfElements;
    T size_s;
  public:
    Stack();
    explicit Stack(std::size_t initialCapacity);
    void push(const T& newElement);
    T pop();
    bool empty();
    T size();
    const T& top();
};
template <typename T>
Stack<T>::Stack()
{
    numberOfElements=0;
    stack=new T[SIZE];
    pointer=&stack[0];
    size_s=SIZE;
}
template <typename T>
Stack<T>::Stack(std::size_t initialCapacity)
{
    numberOfElements=0;
    // TODO: zaimplementuj - parametr to początkowa wielkość tablicy
    initialCapacity=SIZE;
    stack=new T[initialCapacity];
    pointer=&stack[0];
    size_s=SIZE;
}
template <typename T>

void Stack<T>::push(const T& newElement)
{
  // TODO: zaimplementuj
  if(numberOfElements==size_s)
  {
      size_s*=2;
      T *array= new T[size_s];
          for (int i=0;i<SIZE;i++)
          {
              array[i]=stack[i];
          }
      stack = new T[size_s];
      for (int i=0;i<size_s;i++)
      {
          stack[i]=array[i];
      }
      pointer=&stack[size_s/2];
      delete[] array;
      numberOfElements++;
  }
 else

  {
      *pointer = newElement;
      pointer++;
      numberOfElements++;
  }

}
template <typename T>
T Stack<T>::pop()
{
  // TODO: zaimplementuj
    static T t;
    if(numberOfElements!=0)
  {
      pointer--;
      numberOfElements--;
      t=*pointer;
  }
  else
      t=0;
    return t;
}

template <typename T>
bool Stack<T>::empty()
{
    // TODO: zaimplementuj
    if(pointer==stack)
        return true;
    else
        return false;
}
template <typename T>
T Stack<T>::size()
{
    // TODO: zaimplementuj
    return numberOfElements;
}

template <typename T>
const T& Stack<T>::top()
{
    // TODO: zaimplementuj
    static T t;
    if(numberOfElements!=0)
    {
        pointer--;
        t = *pointer;
        pointer++;
    }
    else
        t=0;
    return t;
}
#endif /* STACK_HPP_ */
