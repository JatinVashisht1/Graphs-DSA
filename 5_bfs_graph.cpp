#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<vector<int>> &edges, int source, int destination){
    edges[source].push_back(destination);
    edges[destination].push_back(source);

}

void bfs(vector<vector<int>> &edges, int start, bool* visited){
    if(visited[start]){
        return;
    }
    
    // to do bfs we have to maintain queue
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(q.size()){
        int frontNode = q.front();
        q.pop();
        cout<<frontNode<<" -> ";
        
        // printing all nodes connected to the frontNode, which is a graph node
        for(auto connectedNode: edges[frontNode]){
            cout<<connectedNode<<" ";
            // because there can be loops in graph we have to keep check if the neighbouring node of front node is already visited or not
            if(!visited[connectedNode]){
                visited[connectedNode] = true;
                q.push(connectedNode);
            }
        }
        cout<<"\n";
    }

}


int main(){
vector<vector<int>> edges(6);
addEdge(edges, 0, 1);
addEdge(edges, 0, 2);
addEdge(edges, 1, 2);
addEdge(edges, 1, 3);
addEdge(edges, 4, 5);
addEdge(edges, 5, 3);
bool visited[6] = {false};
bfs(edges, 0, visited);

return 0;
}