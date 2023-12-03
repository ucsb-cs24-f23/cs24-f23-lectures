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
        bool hasEdge(int i, int j) const;
        vector<bool> bfs(int source) const;
        bool isValidPath(const vector<int> & path) const;
        bool isReachable(int source, int dest)const;
        
    private:
        vector<list<int>> adjlist;
        
};
void graph::addEdge(int from, int to){
    adjlist[from].push_back(to);
    adjlist[to].push_back(from);
}
bool graph::hasEdge(int from, int to) const{
    for (auto e : adjlist[from]){
        if(e == to){
            return true;
        }
    }
    return false;
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

bool graph::isReachable(int source, int dest)const{
    vector<bool> visited = bfs(source);
    return visited[dest];
}

bool graph::isValidPath(const vector<int> & path) const{
    int n = path.size();
    for(int i = 0; i < n - 1; i++){
        if(!hasEdge(path[i], path[i+1])){
            return false;
        }
    }
    return true;
}


vector<bool> graph::bfs(int source) const{
    int n = adjlist.size(); // number of vertices
    vector<bool> visited(n, false);
    visited[source] = true;
    queue<int>  q;
    q.push(source);
    cout << source << " ";
    while (!q.empty())
    {
        int u = q.front();
        for(auto v : adjlist[u]){
            if(!visited[v]){
                visited[v] = true;
                cout << v << " ";
                q.push(v);
            }
        }
        q.pop();
    }
    
    return visited;
     
}

int main(int argc, char const *argv[])
{  
    graph g(7);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 1);
    g.addEdge(5, 4);
    cout << "Display graph" << endl;
    g.display();
    cout << endl;
    vector<int> q = {0, 1, 2, 3, 1, 2};
    cout<< "Path: {0, 1, 2, 3, 1, 2} ";
    if(g.isValidPath(q)){
        cout << "exists " << endl;
    } else{
        cout << "does not exist " << endl;
    }
    cout << "Is 6 reachable from 0? " << std::boolalpha << g.isReachable(0, 6) << endl;
    cout << "Is 4 reachable from 0? " << std::boolalpha << g.isReachable(0, 4) << endl;
    cout << "shortest distance from 0 to 5 is " << endl;
    cout << "shortest path is: ";

    return 0;
}
