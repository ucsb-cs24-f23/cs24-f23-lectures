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
        void erase(int value);
        int sum() const;
        void print() const;
        void clear();
    
    private:
        struct Node{
            int data;
            Node* next;
        };
        Node* head;
};

void IntList::push_back(int value){
    return; 
}
void IntList::pop_front(){
    return; 
}
void IntList::pop_back(){
    return; 
}
void IntList::erase(int value){
    return; 
}

void IntList::push_front(int value){
    head = new Node {value, head}; 
}

int IntList::sum() const{
    return 42;
}

void IntList::clear(){
    return; 
}

void IntList::print() const{

}

void test_copy_constructor(){
    IntList x;
    x.push_front(10);
    x.push_front(20);
    IntList y(x); 
    x.clear();
    y.print();
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
