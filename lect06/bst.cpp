//bst.cpp 
#include <iostream>
using namespace std;

// No duplicate keys
class bst{

public:
    bst():root(nullptr){}
    bool search(int value) const;
    int min() const ;
    int max() const;
    bool insert(int value);
    int successor(int value) const;
    int predecessor(int value) const;
    bool erase(int value);
    void inorder() const;
    void preorder() const;
    void postorder() const;

private:
    class BSTNode{
        public:
        BSTNode* parent;
        BSTNode* left;
        BSTNode* right;
        int const data;
        // list initializer 
        BSTNode(int d): data(d){
            left = right = parent = nullptr;
        }
    };
    BSTNode* root;
};