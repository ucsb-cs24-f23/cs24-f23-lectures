//intlist.cpp
#include <iostream>
using namespace std;
// ADT IntList
class IntList{  
    public:
        IntList(){ head = nullptr;}
        ~IntList(){ 
            clear();
            //cout << "Bye" <<endl;
        }
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
        //Helper function
        int sum(Node* h) const;
        void clear(Node* h);
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

int IntList::sum(Node* h) const{
    //Base case
    if(h == nullptr){
        return 0;
    }
    //Recursive case
    return h->data + sum(h->next);

}
int IntList::sum() const{
    // Node* p = head;
    // int result = 0;
    // while(p){
    //     result+= p->data;
    //     p = p->next;
    // }
    return sum(head);
}

void IntList::clear(Node* h){

    if(h==nullptr){
        return;
    }
    clear(h->next);
    delete h;
}
void IntList::clear(){
    clear(head);
    head = nullptr; 
}

void IntList::print() const{
    Node* p = head;
    while(p){
        cout<< p->data << " ";
        p = p->next;
    }
    cout << endl;

}

void test_copy_constructor(){
    IntList x;
    x.push_front(10);
    x.push_front(20);
    IntList y(x); 
    x.clear();
    y.print();
}
void foo(){
    IntList ll; // Stack
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    cout << ll.sum() << endl;;
    ll.print();
    // This code has a memory leak because the nodes
    // on the heap were not deleted
}

int main(int argc, char const *argv[])
{
    foo();
    // int* p = nullptr;
    // cout << *p;
    return 0;
}
