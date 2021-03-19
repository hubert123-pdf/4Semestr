#ifndef DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
#define DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP

template <typename T>
class DoublyLinkedList
{
  private:
    struct DLNode
    {
        T Data;                 //stored Data
        DLNode* prev;           //pointer to the previous Node
        DLNode* next;           //pointer to the next Node
    };
    DLNode *head=NULL;          //Pointer to the first Node
    DLNode *tail=NULL;          //Pointer to the last Node
    size_t size_l=0;            //size of the list
    T head_val;                 //value of the fist Node
    T tail_val;                 //value of the last Node

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
    if(size_l==0)
        return true;
    else
        return false;
}

template <typename T>
std::size_t DoublyLinkedList<T>::size()
{
    return size_l;
}
template <typename T>
void DoublyLinkedList<T>::addFront(const T& newElement)
{
    struct DLNode* new_node =new DLNode;
    new_node->Data=newElement;   //implementing new Node
    new_node->next=head;         //new Node points at the Node that head is pointing
    new_node->prev=NULL;
    head=new_node;               //head points at the new Node
    head_val=newElement;
    if(size_l==0)
        tail=head;              //if list is empty tail points at the new Node
    tail_val=tail->Data;
    size_l++;
}
template <typename T>
void DoublyLinkedList<T>::removeFront()
{

    if(size_l!=0)
    {
        if(size_l>1)
        {
            head = head->next;
            head->prev = NULL;
        }
        head_val = head->Data;
        size_l--;
    }
}
template <typename T>
void DoublyLinkedList<T>::addBack(const T& newElement)
{
    DLNode *new_node=new DLNode;
    new_node->Data=newElement;       //implementing new Node
    new_node->next=NULL;             //implementing new Node
    if(size_l==0)
    {
        head=new_node;
        tail=new_node;
        new_node->prev=NULL;
    }
    else
    {
        new_node->prev=tail;                    //new Node's prev pointer points at the last Node
        tail = head;
        while(tail->next != NULL)               //tail goes through every pointer till the end
            tail = tail->next;                  //then it points at the new node
        tail->next=new_node;
    }
    tail_val=new_node->Data;
    size_l++;
}
template <typename T>
void DoublyLinkedList<T>::removeBack()
{
    for(int i;i<size_l-1;i++)
        head=head->next;
    head->next=NULL;
    tail_val=head->Data;
    size_l--;
}
template <typename T>
const T& DoublyLinkedList<T>::front() const
{
    static T t;
    t=head_val;
    return t;
}
template <typename T>
const T& DoublyLinkedList<T>::back() const
{
    static T t;
    t=tail_val;
    return t;
}
template <typename T>
void DoublyLinkedList<T>::insert(const T& newElement, int index)
{
    DLNode *new_node=new DLNode;
    new_node->Data=newElement;
    DLNode *prevNode=new DLNode;
    DLNode *nextNode=new DLNode;
    prevNode=head;
    nextNode=head;
    for(int i=0;i<index-1;i++)
        prevNode=prevNode->next;   //finding node that will point at the new node
    for(int i=0;i<index;i++)
        nextNode=nextNode->next;   //finding node that will be pointed by new node
    new_node->prev=prevNode;       // prev pointer is pointing at the previous Node
    prevNode->next=new_node;
    new_node->next=nextNode;
}
template <typename T>
void DoublyLinkedList<T>::remove(const T& element)
{
    size_l--;
}

template <typename T>
T& DoublyLinkedList<T>::operator[](int index)
{
    static T t;
    DLNode *new_node=new DLNode;
    new_node=head;
    for(int i =0;i<index;i++)
    {
        new_node=new_node->next;
    }
    t=new_node->Data;
    return t;
}

#endif // DATA_STRUCTURES_DOUBLY_LINKED_LIST_HPP
