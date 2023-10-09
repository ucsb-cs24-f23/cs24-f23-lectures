// linkedlist.cpp
// Non-OOP style implementation to contrast against the OOP style
// implementation in intlist.cpp 
#include <iostream>

struct Node{
  int data;
  Node* next;
};

Node* push_front(Node* h, int value){
  //Node n; // on the stack, goes away after function returns
  // or 
  // Node* p = new Node{value, h}; //On the heap
  // p->data = value;
  // p->next = h;
  return new Node{value, h};
}

int main() {
  Node* head = nullptr;
  head = push_front(head, 10);
  head = push_front(head, 20);
  head = push_front(head, 30);

  return 0;
}