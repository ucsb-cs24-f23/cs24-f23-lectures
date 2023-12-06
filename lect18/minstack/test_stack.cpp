//test_stack.cpp
#include <iostream>
#include <vector>
#include <stack>
#include "minstack.h"
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, -3, 4, 5};
    stack<int> stl_stack;
    for(auto elem : nums){
        stl_stack.push(elem);
    }
    //cout << "Top: " << s.top() << endl;

    while(!stl_stack.empty()){
        cout << "Top: " << stl_stack.top() << endl;
        stl_stack.pop();
    }

}
