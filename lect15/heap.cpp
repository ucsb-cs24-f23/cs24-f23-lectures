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
// Running time: O(n^2)
// Space Complexity: O(1)

void simple_heap_sort(vector<int>& v){
    priority_queue<int> pq; // max - heap: element at the top is the maximum element 
    // Operations: top() // max value - O(1)  , 
    // push(x) - insert x into the pq - O(log n)
    // pop()  - delete the max value - O(log n)
    for (auto e : v ){
        pq.push(e); // upper bounded by  O(log n) - last iteration
    }
    // for loop: O(n log n)

    int i = 0;
    while(!pq.empty()){ // n times
        v[i] = pq.top(); // O(1)
        pq.pop(); // O(log n)
        i++; // O(1)
    }
    // while loop - O(n log n)

}
// overall: running time : O(n log n)
// Space complexity: O(n)



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
    simple_heap_sort(v);
    cout<<"After sorting"<<endl;
    visualize(v);

    return 0;
}
