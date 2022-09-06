#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;

int parent[N];

void make(int i){
    parent[i] = i;
}

int find(int i){
    if(parent[i] == i){
        return i;
    }

    return find(parent[i]);
}

int Union(int x, int y){
    int parent_x = find(x);
    int parent_y = find(y);
    parent[parent_x] = parent_y;
}

int main(){
    int n = 5;
    for(int i = 0; i<n; i++){
        make(i);
    }
    // for(int i = 0; i<n; i++){
    //     cout<<"parent of "<<i<<" is "<<find(i)<<'\n';
    // }

    Union(0, 1);
    Union(1, 3);

    for(int i = 0; i<n; i++){
        cout<<"parent of "<<i<<" is "<<find(i)<<'\n';
    }

    return 0;
}