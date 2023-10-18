//test.cpp
#include <iostream>
#include "bst.h"
using namespace std;
int main(int argc, char const *argv[])
{
    bst b;
    b.insert(42);
    b.insert(32);
    b.insert(12);
    b.insert(50);

    bst c(b); //copy constructor

    return 0;
}