//mystack.cpp
#include "mystack.h"
using namespace std;

template <typename T>
void mystack<T>::push(T value){
    mystack_.push_front(value);    
}

template <typename T>
void mystack<T>::pop(){
    mystack_.pop_front();     
}

template <typename T>
T mystack<T>::top() const{
    return mystack_.front();
}

template <typename T>
bool mystack<T>::empty() const{
    return mystack_.empty();
}
