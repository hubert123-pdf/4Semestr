#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#define SIZE 10
template <typename T>
class Queue
{
    T *queue;
    T *front_pointer;
    T *back_pointer;
    std::size_t size_q;
    T numberOfElements;
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
    queue=new T[SIZE];
    front_pointer=queue;
    back_pointer=queue;
    size_q=0;
    numberOfElements=0;

}

template <typename T>
Queue<T>::Queue(std::size_t initialCapacity)
{
    queue=new T[initialCapacity];
    front_pointer=queue;
    back_pointer=queue;
    numberOfElements=0;
    size_q=0;


}

template <typename T>
void Queue<T>::enqueue(const T& newElement)
{
    /*   if(numberOfElements==++size_q)
    {
        size_q*=2;
        T *array= new T[size_q];
        for (int i=0;i<SIZE;i++)
        {
            array[i]=queue[i];
        }
        queue = new T[size_q];
        for (int i=0;i<size_q;i++)
        {
            queue[i]=array[i];
        }
        back_pointer=&queue[size_q/2];
        delete[] array;
        numberOfElements++;
    }

    else*/
    {
        *back_pointer=newElement;
        back_pointer++;
        size_q++;
        numberOfElements++;
    }

}

template <typename T>
T Queue<T>::dequeue()
{
    T value;
    value=*front_pointer;
    front_pointer++;
    size_q--;
    return value;

}
template <typename T>
bool Queue<T>::empty()
{
    if(front_pointer==back_pointer)
        return true;
    else
        return false;
}

template <typename T>
std::size_t Queue<T>::size()
{
    return size_q;
}

template <typename T>
const T& Queue<T>::front()
{
    static T t;
    t=*front_pointer;
    return t;
}

#endif /* QUEUE_HPP_ */
