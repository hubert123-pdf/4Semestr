//
// Created by hubert on 09.03.2021.
//
#include <list>
#include <iostream>
#include <time.h>
#include <string>
#ifndef PAMSIPROJEKT1STRUKTURYDANYCH_LIST_H
#define PAMSIPROJEKT1STRUKTURYDANYCH_LIST_H

class list
{
    std::list<int> container;

  public:
    list()
    {
        srand(time(NULL));
    }
     void description()
    {
        std::cout<<
        "1.Show whole list"<<std::endl<<
        "2.Show size"<<std::endl<<
        "3.Show last element"<<std::endl<<
        "4.Show first element"<<std::endl<<
        "5.Add random number at the front"<<std::endl<<
        "6.Add random number at the end"<<std::endl<<
        "7.Add k elements at the front"<<std::endl<<
        "8.Add l elements at the end"<<std::endl<<
        "9.Pop element at the end"<<std::endl<<
        "10.Pop j elements at the end"<<std::endl<<
        "11.Pop all the elements"<<std::endl;
    }
    bool empty()
    {
     if (container.empty())
         return true;
     else
         return false;
    }
    void show_All()
    {
        for(auto const& v:container)
        {
            std::cout << v <<std::endl;
        }
    }
    int size()
    {
        return container.size();
    }
    int front()
    {
        return container.front();
    }
    int back()
    {
        return container.back();
    }
    int random()
    {
        int random=rand()%10+3;
        return random;
    }
    void push_front(int x)
    {
        container.push_front(x);
    }
    void push_back(int x)
    {
        container.push_back(x);
    }
    void add_many_front(int x)
    {
        for(int i=0;i<x;i++)
        {
            int j;
            std::cout << "Value: ";
            std::cin>>j;
            container.push_front(j);
        }
    }
    void add_many_back(int x)
    {
        for(int i=0;i<x;i++)
        {
            int j;
            std::cout << "Value: ";
            std::cin>>j;
            container.push_back(j);
        }
    }
    void pop_back()
    {
        container.pop_back();
    }
    void pop_many_back(int x)
    {
        for(int i=0;i<x;i++)
            {
                if(container.empty())
                    break;
                else
                    container.pop_back();
            }
    }
    void pop_all()
    {
        for(int i=0;i<=container.size();i++)
        {
            container.pop_back();
        }
    }








};
#endif // PAMSIPROJEKT1STRUKTURYDANYCH_LIST_H
