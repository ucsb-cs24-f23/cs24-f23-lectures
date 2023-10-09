//intlist.cpp
#include <iostream>
using namespace std;
// ADT IntList
class IntList{  
    public:
        IntList(){ head = nullptr;}
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void pop_back();
        int sum();
        void clear();
        void erase(int value);
    private:
        struct Node{
            int data;
            Node* next;
        };
        Node* head;
};

void IntList::push_front(int value){
    head = new Node {value, head}; 
}
void IntList::push_back(int value){
    return; 
}
void IntList::pop_front(){
    return; 
}
void IntList::pop_back(){
    return; 
}
int IntList::sum(){
    return 42;
}
void IntList::clear(){
    return; 
}
void IntList::erase(int value){
    return; 
}

int main(int argc, char const *argv[])
{
    IntList ll;

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    cout << ll.sum() << endl;;
    return 0;
}
