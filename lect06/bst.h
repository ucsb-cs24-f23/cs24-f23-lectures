//bst.cpp 
#include <iostream>
using namespace std;

// No duplicate keys
class bst{

public:
    bst():root(nullptr){}
    bst(const bst& other);
    bool search(int value) const;
    int min() const ;
    int max() const;
    bool insert(int value){return false;}
    int successor(int value) const;
    int predecessor(int value) const;
    bool erase(int value);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void clear();

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
    void inorder(BSTNode* r) const;
    void preorder(BSTNode* r) const;
    void postorder(BSTNode* r) const;
    void preorder_insert(BSTNode* other);
    void clear(BSTNode* r);
};
