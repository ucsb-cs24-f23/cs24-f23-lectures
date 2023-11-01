//test_stack.cpp
#include <iostream>
#include <stack>
#include <vector>
#include "mystack.h"
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums {10, 5, -4, 30};
    vector<string> colors {"red", "blue", "green"};
    mystack<int> s;
    mystack<string> m;

    for (auto elem : nums){
        s.push(elem);
    }
    auto x = 10;
    cout << x << endl;

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
