// heap.cpp
// Lecture 15: Heaps and application to sorting
// Handout: https://bit.ly/CS24-Heaps-lect15

#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#include <algorithm>

using namespace std;

void visualize(vector<int>& nums){
     for(auto item: nums){
        for(int i = 0; i< item;i++){
             cout<<"-";
         }
        cout<<endl;
    }
    cout<<endl;

}
void selection_sort(vector<int>& v){
    for (int i = 0; i < v.size(); i++){ 
        int index = i;
        for (int j = i + 1; j < v.size(); j++){
            if(v[j] > v[index]){
                index = j;
            }
        }
        if(index != i){
            int temp = v[index];
            v[index] =  v[i];
            v[i] = temp;    
        }
    }
}

void simple_heap_sort(vector<int>& v){

}

int main(int argc, char const *argv[])
{
   // srand(time(NULL));
    vector<int> v {8, 50, 74, 59, 31, 73, 45, 79, 24, 10, 41, 66, 93, 43, 88, 4, 28, 30, 41, 13, 4, 70, 10, 58, 61, 34, 100, 79, 17, 36};
    // Another example {1, 5, 3, 6, 4, 1, 7, 8, 4}
    // for(int i = 0; i< 30; i++){
    //     v.push_back(rand() % 100 + 1);
    // }
    cout<<"Before"<<endl;
    visualize(v);
    selection_sort(v);
    cout<<"After sorting"<<endl;
    visualize(v);

    return 0;
}
