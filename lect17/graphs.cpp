//graphs.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <iomanip>
using namespace std;

class graph{
    public:
        graph(int n){
            adjlist = vector<list<int>>(n);
        }
        void addEdge(int from, int to);
        void display() const;
        vector<bool> bfs(int source) const;        
        // Implement depth-first search
        void dfs(int v, vector<bool>& visited) const;
        // Implement a variation of BFS that computes the shortest path from a source 
        // vertex to all vertices reachable from it
        pair<vector<int> , vector<int> > bfs_shortest_path(int source) const;
    
    private:
        vector<list<int>> adjlist;   
};

// Directed Graph! 
void graph::addEdge(int from, int to){
    adjlist[from].push_back(to);
  //  adjlist[to].push_back(from);
}

void graph::display() const{
    for(int i  = 0 ; i < adjlist.size(); i++){
        cout<<setw(3)<< i <<" : ";
        for (auto elem: adjlist[i]){
            cout <<setw(2)<<elem <<" ";
        }
        cout <<endl;
    }
}


// Running time analysis of DFS
// Let n be the number of vertices, m is the number of edges
// Observation 1: Every vertex is visited once when DFS function is called on that vertex
// The dfs is called k times, where k is the number of vertices reachable from the source 
// k <= n, therefore dfs is called no more than n times

// Observation 2: Every directed edge (v, u) is explored exactly once
// when we call dfs on vertex v and check if neighbor u is visited or not

// Observation 3: The for loop runs a variable number of times,
// examine the number of times the statements inside the loop run for 
// the *** entire duration of the program***. 
// This is actually a valid analysis technique! 

pair<vector<int> , vector<int> > graph::bfs_shortest_path(int source) const{
    int n = adjlist.size(); // O(1)
    vector<bool> visited(n, false); // O(n)
    vector<int> dist(n, -1); //  O(n)
    vector<int> prev(n, -1); //O(n)
    queue<int> q; // O(1)
    visited[source] = true; // O(1)
    q.push(source); // O(1)
    dist[source] = 0; // O(1)
    cout << source << " "; // O(1)
    while(!q.empty()){
        int v = q.front();  // O(n) - observation 1 for entire program
        q.pop(); // O(n) for the entire program 
        for(auto u: adjlist[v]) { // Go through all neighbors of v
            if(!visited[u]){ // O(m) by observation 2 & 3, fact there are m edges, for entire duration of the program 
               visited[u] = true; // O(n) for the whole program
               cout << u << " ";
               dist[u] = dist[v] + 1;
               prev[u] = v;
               q.push(u); // O(1)
            }
        }
    }
    return make_pair(dist, prev);
}
// Total  O( n + m)
// Space: O(n)  //assume a star network with max of n - 1 neighbors 



// Running time analysis of DFS
// Let n be the number of vertices, m is the number of edges
// Observation 1: Every vertex is visited once when DFS function is called on that vertex
// The dfs is called k times, where k is the number of vertices reachable from the source 
// k <= n, therefore dfs is called no more than n times

// Observation 2: Every directed edge (v, u) is explored exactly once
// when we call dfs on vertex v and check if neighbor u is visited or not

// Observation 3: The for loop runs a variable number of times,
// examine the number of times the statements inside the loop run for 
// the *** entire duration of the program***. 
// This is actually a valid analysis technique! 

void graph:: dfs(int v, vector<bool>& visited) const{
    visited[v] = true; // O(n) for the entire duration of the program, observationa 1 & 3
    cout << v << " "; // O(n) 
    for(auto u: adjlist[v]) { // Go through all neighbors of v
        if(!visited[u]){ // O(m) by observation 2 & 3, fact there are m edges, for entire duration of the program 
            dfs(u, visited); // O(n) by obs 1 & 3
        }
    }
}
// Total running time = O(n)  + O(n) + O(m) + O(n) = O(n + m)
// Space complexity: What is the maximum depth of the recursion is O(n)
// O(n)

int main(int argc, char const *argv[])
{   
    int num_vertices = 5;
    graph g(num_vertices);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);   
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Display graph" << endl;
    g.display();
    cout << endl;

    cout << "Depth first search" << endl;
    vector<bool> visited(num_vertices, false);
    g.dfs(0, visited);
    
    auto result = g.bfs_shortest_path(0);
    auto dist = result.first;
    auto ancestor = result.second;

    cout << "\nShortest distance and path (using BFS) from 0 to " << endl;
    for (int j = 0 ; j < num_vertices; j ++ ){
        cout << j << ": dist = " << dist[j] << " path (in reverse) " ;
        int x = j;
        cout << "[";
        while(ancestor[x] != -1){
            cout << x << ", ";
            x = ancestor[x];
        }
        cout << x << "]" << endl;
    }
    return 0;
}
