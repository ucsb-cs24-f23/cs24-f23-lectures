//bst.cpp
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

private:
    class BSTNode{
        public:
        BSTNode* parent;
        BSTNode* left;
        BSTNode* right;
        int const data;
        // list initialization 
        BSTNode(int d): data(d){
            left = right = parent = nullptr;
        }
    };
    BSTNode* root;

};