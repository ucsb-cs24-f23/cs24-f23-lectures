//mystack.h
#include <list>
using namespace std;

#ifndef MYSTACK_H
#define MYSTACK_H

template <typename T>
class mystack
{
private:
    list<T> mystack_;
    
public:
    void push(T value);
    void pop();
    T top() const;
    bool empty() const;
};

#include "mystack.cpp"
#endif