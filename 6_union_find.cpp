#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 10;

int parent[N];
// array to track size of each tree
int size[N];

void make(int i){
    parent[i] = i;
    size[i] = 1;
}

int find(int i){
    if(parent[i] == i){
        return i;
    }
    
    // OPTIMIZATION: make parent of leaf nodes parent of their parent only
    // This will prevent tree from becoming skewed
    // This is called PATH COMPRESSION
    return parent[i] = find(parent[i]);
}

int Union(int x, int y){
    int parent_x = find(x);
    int parent_y = find(y);
    if(parent_x != parent_y){
        if(parent_x != parent_y)
            swap(parent_x, parent_y);
        parent[parent_x] = parent_y;
        // OPTIMIZATION: this is called union find by SIZE
        // this operation will prevent tree from getting skewed because we are merging node with tree of smaller size
        size[parent_x] += parent_y;
    }
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
    Union(2, 3);

    for(int i = 0; i<n; i++){
        cout<<"parent of "<<i<<" is "<<find(i)<<'\n';
    }

    return 0;
}