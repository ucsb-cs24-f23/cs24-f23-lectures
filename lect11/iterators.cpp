
#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

template <class T>
void printKeys(T& t){
    for (auto elem : t){
        cout << elem << " ";
    }
    cout << endl;
}

template <class T>
void printKeysLongForm(T& t){
    for (typename T::iterator it = t.begin(); it != t.end(); it++ ){
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v {30, 20, 25, 40, 35, 60};
    list<int> l {30, 20, 25, 40, 35, 60};
    set<int> s {30, 20, 25, 40, 35, 60}; // no duplicates and balanced BST!!

    cout << "Iterate through vector "<< endl;
    printKeys(v);
    cout << endl;
    cout << "Iterate through linked list "<< endl;
    printKeysLongForm(l);
    cout << endl;
    cout << "Iterate through set "<< endl;
    printKeys(s);
    return 0;
}

