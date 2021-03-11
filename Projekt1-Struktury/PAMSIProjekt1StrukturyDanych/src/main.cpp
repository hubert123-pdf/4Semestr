#include "../include/DT/stack.h"
#include "../include/DT/queue.h"
#include "../include/DT/list.h"

int main()
{
    int c;
    std::cout<<"Choose data structure:"<<std::endl<<"1.stack  2.queue 3.list"<<std::endl;
    std::cin>>c;

    if(c==1)
    {
        stack stack;
        while(true)
        {
            stack.description();
            std::cin >> c;
            switch(c)
            {
                case 1:
                {
                    int x;
                    std::cout << "value: ";
                    std::cin >> x;
                    stack.push(x);
                    break;
                }
                case 2:
                {
                    std::cout<<"How many? :";
                    int m;
                    std::cin>>m;
                    stack.push_many(m);
                    break;
                }
                case 3:
                {
                    if(stack.empty())
                    {
                        std::cout<<"EMPTY!!!";
                    }
                    else
                    {
                        stack.show_top();
                    }
                    break;
                }
                case 4:
                {
                    if(stack.empty())
                    {
                        std::cout<<"EMPTY!!!";
                    }
                    else
                    {
                        stack.pop();
                    }
                    break;
                }
                case 5:
                {
                    if(stack.empty())
                    {
                        std::cout<<"EMPTY!!!";
                    }
                    else
                    {
                        int m;
                        std::cout << "How many? :";
                        std::cin >> m;
                        stack.pop_many(m);
                    }
                    break;
                }
                case 6:
                {
                    stack.show_size();
                    break;
                }
                default:
                    break;
            }
        }
    }
    if(c==2)
    {
        queue queue;
        while(true)
        {
            std::cout<<std::endl;
            queue.description();
            std::cin >> c;
            switch(c)
            {
                case(1):
                {
                    int x;
                    std::cout << "value: ";
                    std::cin >> x;
                    queue.push(x);
                    break;
                }
                case(2):
                {
                    std::cout<<"How many? :";
                    int m;
                    std::cin>>m;
                    queue.push_many(m);
                    break;
                }
                case(3):
                {
                    if(queue.empty())
                    {
                        std::cout<<"EMPTY!!!";
                    }
                    else
                        queue.pop();
                    break;
                }
                case(4):
                {
                    if(queue.empty())
                    {
                        std::cout<<"EMPTY!!!";
                    }
                    else
                    {
                        int m;
                        std::cout << "How many? :";
                        std::cin >> m;
                        queue.pop_many(m);
                    }
                    break;
                }
                case(5):
                {
                    if(queue.empty())
                        std::cout<<"EMPTY!!!";
                    else
                        queue.front();
                    break;
                }
                case(6):
                {
                    queue.size();
                    break;
                }
                default:
                    break;
            }
            std::cout<<std::endl;
        }
    }
    if(c == 3)
    {
        list list;
        while(true)
        {
            std::cout<<std::endl;
            list.description();
            std::cin>>c;
                switch(c)
                {
                    case 1:
                    {
                        list.show_All();
                        break;
                    }
                    case 2:
                    {
                        std::cout<<list.size();
                        break;
                    }
                    case 3:
                    {
                        std::cout<<list.back();
                        break;
                    }
                    case 4:
                    {
                        std::cout<<list.front();
                        break;
                    }
                    case 5:
                    {
                        list.push_front(list.random());
                        break;
                    }
                    case 6:
                    {
                        list.push_back(list.random());
                        break;
                    }
                    case 7:
                    {
                        int x;
                        std::cout<<"How many? :";
                        std::cin>>x;
                        list.add_many_front(x);
                        break;
                    }
                    case 8:
                    {
                        int x;
                        std::cout<<"How many? :";
                        std::cin>>x;
                        list.add_many_back(x);
                        break;
                    }
                    case 9:
                    {
                        if(list.empty())
                        {
                            std::cout<<"EMPTY!";
                        }
                        else
                        {
                            list.pop_back();
                        }
                        break;
                    }
                    case 10:
                    {
                        if(list.empty())
                            std::cout<<"EMPTY!";
                        else
                        {
                            int x;
                            std::cout << "How many? :";
                            std::cin >> x;
                            list.pop_many_back(x);
                        }
                        break;
                    }
                    case 11:
                    {
                        if(list.empty())
                            std::cout<<"ALREADY EMPTY!";
                        else
                            list.pop_all();
                        break;
                    }
                    default:
                        break;
                }
            }
    }
}
