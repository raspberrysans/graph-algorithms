//Depth first search in a directed graph. The graph may or may not be disconnected.
//This program prints the graph after DFS traversal

#include <vector>
#include <iostream>
#include <stack>

using namespace std;
//int vertices = 6;
class Graph{
    int v;
    //the adjacency list is a vector of vectors.
    vector<vector<int> > adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void depthfirstsearch(int start, vector<bool> &visited);

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

void Graph::depthfirstsearch(int start, vector<bool> &visited){

    stack<int> dfstack;
    dfstack.push(start);

    while(!dfstack.empty()){
        
        int val = dfstack.top();
        if(!visited[val]){
            visited[val] = true;
            cout <<val<<" ";
        }
        
        dfstack.pop();
        for(auto it = adj[val].begin()+1;it != adj[val].end(); it++){
            if(!visited[*it]){
                dfstack.push(*it);

            }
        }
    }

}

int main(){
    int vertices = 5;
    Graph g(vertices);
    vector<bool> visited(vertices, false);
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
    for(int i=0; i<vertices; i++){
        if(!visited[i])
            g.depthfirstsearch(i, visited);
    }
 
    return 0;
}