#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    //in case of weighted edges define vector<pair<int,int>> adj[n + 1]; where one will be for storing edge and other for its weight

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}


// TC:
// Initialization: O(V)
// Inserting all edges: O(E) amortized
// Total: O(V + E)

// SC: O(V + E)