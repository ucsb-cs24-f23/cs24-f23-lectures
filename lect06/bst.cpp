//bst.cpp 
#include <iostream>
#include "bst.h"
using namespace std;

void bst::inorder(BSTNode* r) const{
    if(!r) return;
    inorder(r->left);
    cout << r->data << " "; //visit the node
    inorder(r->right);
}
void bst::preorder(BSTNode* r) const{
    if(!r) return;
    cout<< r->data << " ";
    preorder(r->left);
    preorder(r->right);
}
void bst::postorder(BSTNode* r) const{
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    cout<< r->data << " ";

}
void bst::preorder_insert(BSTNode* other){
    if(!other) return;
    insert(other->data);
    preorder_insert(other->left);
    preorder_insert(other->right);

}
bst::bst(const bst& other){
    root = nullptr;
    preorder_insert(other.root);
}
 void bst::clear(BSTNode* r){
    if(!r) return;
    clear(r->left);
    clear(r->right);
    delete r;
 }

