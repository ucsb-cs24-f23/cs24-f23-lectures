
#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class T>
void printKeys(T& t){
    for (auto elem : t){
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v {30, 20, 25, 40, 35, 60};
    list<int> l {30, 20, 25, 40, 35, 60};
    cout << "Iterate through vector "<< endl;
    printKeys(v);
    cout << endl;
    cout << "Iterate through linked list "<< endl;
    printKeys(l);
   
    return 0;
}

