//Breadth first search in a directed graph
//This program prints the graph after BFS traversal

#include <vector>
#include <iostream>
#include <queue>

using namespace std;
class Graph{
    int v;
    //the adjacency list is a vector of vectors.
    vector<vector<int> > adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void breadthfirstsearch(int start);

};
//Constructor
Graph::Graph(int V)
{
    this->v = V;
    //initializing the adjacency list
    for(int i=0; i<this->v; i++){
        vector<int> v1;
        v1.push_back(i);
        adj.push_back(v1);
    }
}
//
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::breadthfirstsearch(int start){
    vector<bool> visited(v, false);

    visited[start] = true;
    queue<int> bfsqueue;
    bfsqueue.push(start);

    while(!bfsqueue.empty()){
        int val = bfsqueue.front();
        cout <<val<<" ";
        bfsqueue.pop();
        for(auto it = adj[val].begin()+1;it != adj[val].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                bfsqueue.push(*it);

            }
        }
    }
    cout <<endl;

}

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
 
    g.breadthfirstsearch(2);
 
    return 0;
}