#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>> &edges, int start, int end){
    edges[start].push_back(end);
    edges[end].push_back(start);
}


// similar to dfs in trees but we can have multiple nodes connected to one node 
void dfs(vector<vector<int>> &edges, int start, bool* visited){
    if(visited[start]){
        return;
    }
    
    cout<<start<<" ";
    visited[start] = true;
    for(auto edge: edges[start]){
        // cout<<visited[edge]<<"\n"
        if(!visited[edge]){
            dfs(edges, edge, visited);
            // cout<<"Edge is "<<edge<<"\n";
        }
    }
}

int main(){
vector<vector<int>> adjVec(5);
    addEdge(adjVec, 0, 3);
    addEdge(adjVec, 0, 2);
    addEdge(adjVec, 2, 1);
    addEdge(adjVec, 3, 2);
    bool visited[5] = {false};
    dfs(adjVec, 0, visited);
return 0;
}