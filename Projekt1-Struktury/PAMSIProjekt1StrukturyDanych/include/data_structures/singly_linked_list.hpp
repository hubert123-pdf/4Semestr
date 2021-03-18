#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP
#define DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP

template <typename T>
class SinglyLinkedList
{
    struct Node
    {
        T Data;                 //Stored data
        struct Node* next;      //Pointer to the new Node
    };
    Node *head=NULL;            //Pointer to the first Node
    Node *tail=NULL;            //Pointer to the last Node
    size_t size_l=0;            //Size of the list
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
bool SinglyLinkedList<T>::empty()
{
    if(size_l==0)
        return true;
    else
        return false;
}

template <typename T>
std::size_t SinglyLinkedList<T>::size()
{
    return size_l;
}

template <typename T>
void SinglyLinkedList<T>::addFront(const T& newElement)
{
    struct Node* new_node =new Node;
    new_node->Data=newElement;   //implementing new Node
    new_node->next=head;         //new Node points at the Node that head is pointing
    head=new_node;               //head points at the new Node
    head_val=newElement;
    if(size_l==0)
        tail=head;              //if list is empty tail points at the new Node
    tail_val=tail->Data;
    size_l++;
}

template <typename T>
void SinglyLinkedList<T>::removeFront()
{
    // TODO: zaimplementuj
    if(size_l!=0)
    {
        if(size_l>1)
            head = head->next;
        head_val = head->Data;
        size_l--;
    }
}

template <typename T>
void SinglyLinkedList<T>::addBack(const T& newElement)
{
    Node *new_node=new Node;
    new_node->Data=newElement;       //implementing new Node
    new_node->next=NULL;             //implementing new Node
    if(size_l==0)
    {
        head=new_node;
        tail=new_node;
    }
    else
    {
        tail = head;
        while(tail->next != NULL)               //tail goes through every pointer till the end
            tail = tail->next;                  //then it points at the new node
        tail->next=new_node;
    }
    tail_val=new_node->Data;
    size_l++;
}
template <typename T>
void SinglyLinkedList<T>::removeBack()
{
    // TODO: zaimplementuj
    for(int i;i<size_l-1;i++)
        head=head->next;
    tail_val=head->Data;
    size_l--;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const
{
    static T t;
    t=head_val;
    return t;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const
{
    static T t;
    t=tail_val;
    return t;
}

template <typename T>
void SinglyLinkedList<T>::insert(const T& newElement, int index)
{
    Node *new_node=new Node;
    new_node->Data=newElement;
    Node *prevNode=new Node;
    Node *nextNode=new Node;
    prevNode=head;
    nextNode=head;
    for(int i=0;i<index-1;i++)
        prevNode=prevNode->next;   //finding node that will point at the new node
    for(int i=0;i<index;i++)
        nextNode=nextNode->next;   //finding node that will be pointed by new node
    prevNode->next=new_node;
    new_node->next=nextNode;
}

template <typename T>
void SinglyLinkedList<T>::remove(const T& element)
{
    size_l--;
}

template <typename T>
T& SinglyLinkedList<T>::operator[](int index)
{
    static T t;
    Node *new_node=new Node;
    new_node=head;
    for(int i =0;i<index;i++)
    {
        new_node=new_node->next;
    }
    t=new_node->Data;
    return t;
}
#endif // DATA_STRUCTURES_SINGLY_LINKED_LIST_HPP
