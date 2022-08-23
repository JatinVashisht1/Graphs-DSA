#include<iostream>
#include<vector>
using namespace std;


// using array of vector
void addEdge(vector<int> adj[], int source, int destination){
    adj[source].push_back(destination);
    adj[destination].push_back(source);
}

void printGraph(vector<int> adj[], int size){
    for(int i = 0; i<size; i++){
        cout<<i<<"-> ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}

// using vector of vector
void addEdgeVec(vector<vector<int>> &adj, int source, int destination){
    adj[source].push_back(destination);
    adj[destination].push_back(source);
}

void printGraphVec(vector<vector<int>> &adj){
    for(int i = 0; i<adj.size(); i++){
        cout<<i<<"-> ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<'\n';
    }
}


int main(){
    vector<int> adj[5];
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 2);
    printGraph(adj, 5);
    cout<<"--------\n";
    vector<vector<int>> adjVec(5);
    addEdgeVec(adjVec, 0, 3);
    addEdgeVec(adjVec, 2, 1);
    addEdgeVec(adjVec, 3, 2);
    printGraphVec(adjVec);
    return 0;
}