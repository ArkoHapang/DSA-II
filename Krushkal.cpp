#include<bits/stdc++.h>
using namespace std;

int find(int node, vector<int>&parent){

    if(node == parent[node])
        return node;

    return parent[node] = find(parent[node], parent);
}

void Union(int X, int Y, vector<int>&parent){

    int par_x = find(X, parent);
    int par_y = find(Y, parent);

    if(par_x != par_y){

        parent[par_y] = par_x;
    }
}

bool compare(vector<int>&a, vector<int>&b){

    return a[2] < b[2];
}

int kruskalsMST(int V, vector<vector<int>> &edges){


    sort(edges.begin(), edges.end(), compare);

    vector<int>parent(V);

    for(int i = 0; i < V; i++){

        parent[i] = i;
    }

    int sum = 0;

    for(auto edge : edges){

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(find(u, parent) != find(v, parent)){

            sum += w;

            Union(u, v, parent);
        }
    }

    return sum;
}

int main(){

    int V, E;

    cout<<"Please Enter number of vertices and edges"<<endl;

    cin>>V>>E;

    vector<vector<int>>edges;

    int u, v, w;

    for(int i = 0; i < E; i++){

        cout<<"Enter edge (u v w): ";

        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }

    int ans = kruskalsMST(V, edges);

    cout<<"Minimum Spanning Tree Cost = "<<ans<<endl;
}
