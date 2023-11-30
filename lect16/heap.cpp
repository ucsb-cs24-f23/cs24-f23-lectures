// heap.cpp
// Lecture 16: Heaps and application to sorting
// Handout: https://bit.ly/CS24-Heaps-lect15

#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#include <algorithm>
#include <cmath>

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

void bubble_down(vector<int> & v, int i, int size){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int max_index = i;
    int n = size;
    cout << "-";
    if(left < n){
        if(v[left] > v[max_index]){
            max_index= left;
        }
    }
    if(right < n){
        if(v[right] > v[max_index]){
            max_index= right;
        }
    }
    if(max_index != i){
        swap(v[i], v[max_index]);
        bubble_down(v, max_index, n);
    }

}



void heapify_v0(vector<int> & v){
   // converts vector into a max heap
    int n = v.size(); 
    for(int i = (n - 1) ; i >= 0; i--){
        bubble_down(v, i, n);
    }
}

void heapify(vector<int> & v){
   // converts vector into a max heap
    int n = v.size(); 
    int h = log2(n); //height of the heap
   // cout << "height = " << h << endl;
    for(int l = (h - 1) ; l >= 0; l--){ // h
        cout <<" level = "<< l <<": ";
        for(int i = pow(2, l + 1) - 2 ; i >= pow(2, l) - 1 ; i--){ // 2 ^ l
           bubble_down(v, i, n); // h - l
           cout << "|" ;
        }
        cout << endl;
    }
}

void heap_sort(vector<int> & v){
    heapify(v);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        // reduce the size of the heap by 1
        bubble_down(v, 0, i);
    }   
}

int main(int argc, char const *argv[])
{
   // srand(time(NULL));
    vector<int> v {8, 50, 74, 59, 31, 73, 45, 79, 24, 10, 41, 66, 93, 43, 88, 4, 28, 30, 41, 13, 4, 70, 10, 58, 61, 34, 100, 79, 17, 36};
    //vector<int> v  {1, 5, 3, 6, 4, 1, 7, 8, 4};
    for(int i = 0; i< 30; i++){
        v.push_back(rand() % 100 + 1);
    }
    // cout<<"Before"<<endl;
    // visualize(v);
    heapify(v);

    // for(auto e : v){
    //     cout << e << " ";
    // }
    // cout << endl;
    // cout<<"After sorting"<<endl;
    // visualize(v);
    return 0;
}
