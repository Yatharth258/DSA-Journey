#include <bits/stdc++.h>
using namespace std;

int main(){


    int n,m;
    //this is standard input way of graphs where n means number of nodes and m means number of edges
    cin>>n>>m;


    int adj[n+1][n+1] = {};

    //graph is being stored in the form of matrix 
    for(int i=0 ; i<m ; i++){
        int u,v; // standard way of inputting like which two nodes are connected , ex- if u,v = 2,4 that means there is a node between those two nodes

        cin>>u>>v;

        adj[u][v]=1;
        adj[v][u]=1;
        //in case of weighted graph you can write edge as adj[v][u]=wt{weight};
        //in case of directed graph one of the upper two line will be missing;
    }
    return 0;
}


// TC:
// Initialization: O(V^2)
// Inserting all edges: O(E)
// Total: O(V^2 + E)

// SC: O(V^2)
//where V= number of edges 