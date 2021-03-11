//
// Created by hubert on 09.03.2021.
//
#include <stack>
#include <iostream>
#ifndef PAMSIPROJEKT1STRUKTURYDANYCH_STACK_H
#define PAMSIPROJEKT1STRUKTURYDANYCH_STACK_H
class stack
{
    std::stack<int> container;
  public:
    void description()
    {
        std::cout<<" STACK "<<std::endl<<"1.Add new element. "<<std::endl<<"2.Add m elements "
                <<std::endl<<"3.Show top element"<<std::endl<<"4.Pop element"<<std::endl<<"5.Pop k elements"
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
    void show_top()
    {
        std::cout<<container.top()<<std::endl;
    }
    void pop()
    {
        container.pop();
    }
    void show_size()
    {
        std::cout<<container.size()<<std::endl;
    }
    bool empty()
    {
        return container.empty();
    }

};

#endif // PAMSIPROJEKT1STRUKTURYDANYCH_STACK_H
