//
// Created by hubert on 09.03.2021.
//
#include <queue>
#include <iostream>
#ifndef PAMSIPROJEKT1STRUKTURYDANYCH_QUEUE_H
#define PAMSIPROJEKT1STRUKTURYDANYCH_QUEUE_H
class queue
{
    std::queue<int> container;
  public:
    void description()
    {
        std::cout<<" QUEUE "<<std::endl<<"1.Add new element. "<<std::endl<<"2.Add m elements "
                 <<std::endl<<"3.Pop element"<<std::endl<<"4.Pop k elements"<<std::endl<<"5.Show first element"
                 <<std::endl<<"6.Show size"<<std::endl;
    }
    void push(int x)
    {
        container.push(x);
    }
    void push_many(int m)
    {
        for(int i = 0; i < m; i++)
        {
            int x;
            std::cout << "Value: ";
            std::cin >> x;
            container.push(x);
        }
    }
    void pop()
    {
        container.pop();
    }
    void pop_many(int m)
    {
        for (int i=0;i<m;i++)
        {
            if(container.empty())
                break;
            else
            container.pop();
        }
    }
    void front()
    {
        std::cout<<container.front();
    }
    void size()
    {
        std::cout<<container.size();
    }
    bool empty()
    {
        return container.empty();
    }

};
#endif // PAMSIPROJEKT1STRUKTURYDANYCH_QUEUE_H
