#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#define SIZE 10
template <typename T>
class Queue
{
    T *queue;               //array that stores elements
    T *front_pointer;       //pointer on the first element
    T *back_pointer;        //pointer on the last element
    std::size_t size_q;     //number of the stored elements
    T value;                //value of the current capacity
    T last_capacity;        //value of the last used capacity (to prevent not necessary increase of an array)
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
}

template <typename T>
Queue<T>::Queue(std::size_t initialCapacity)
{
    queue=new T[initialCapacity];
    front_pointer=queue;
    back_pointer=queue;
    size_q=0;
    value=initialCapacity;
    last_capacity=0;
}

template <typename T>
void Queue<T>::enqueue(const T& newElement)
{
    //Increasing size of an array (X2)
    if((size_q==value)  &&  (size_q!=last_capacity))
    {
        last_capacity=value;
        value*=2;
        T *array= new T[value];
        for (int i=0;i<value;i++)
        {
            array[i]=queue[i];
        }
        queue = new T[value];
        for (int i=0;i<value;i++)
        {
            queue[i]=array[i];
        }
        back_pointer=&queue[value/2];
        queue[value/2];
        front_pointer=&queue[0];
        delete[] array;
        *back_pointer=newElement;
        back_pointer++;
        size_q++;
    }
else
    {
        *back_pointer=newElement;
        back_pointer++;
        size_q++;
    }

}

template <typename T>
T Queue<T>::dequeue()
{
    T value;
    size_q--;
    back_pointer--;
    value=*front_pointer;
    for(int i=0;i<size_q+1;i++)
    {
        queue[i]=queue[i+1];
    }
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