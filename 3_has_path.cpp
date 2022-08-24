#include <bits/stdc++.h>
using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};

bool hasPath(vector<Edge> graph[], int source, int destination, bool visited[]){
    if(source == destination){
        return true;
    }
    visited[source] = true;
    
    for(auto edge: graph[source]){
        cout<<"edge is "<<edge.nbr<<"\n";
        if(visited[edge.nbr] == false){
            bool hasNbrPath = hasPath(graph, edge.nbr, destination, visited);
            if(hasNbrPath){
                return true;
            }
        }
    }
    return false;
}

int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }

  int src;
  cin >> src;
  int dest;
  cin >> dest;
  // write your code here
  bool visited[vtces];
  cout << hasPath(graph, src, dest, visited);


}
