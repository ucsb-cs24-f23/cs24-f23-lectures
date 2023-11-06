// testbst.cpp:
// Modified version of lab03 starter code for demo purposes

#include "bst.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> v{6, 4, 12, 2, 1, 3, 5, 10, 20};
    BST b;
    for (auto elem : v){
        b.insert(elem);
    }
    cout << "Traverse bst in preorder" << endl;
    b.printPreOrder();
    cout << endl;
    cout << "Traverse bst breadth first"<<endl;
    b.printBreadthFirst();
  
    return 0;
}


