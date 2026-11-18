
#include <bits/stdc++.h>
using namespace std;

// DFS Function
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

    vis[node] = 1;

    // Traverse all neighbours
    for(auto it : adj[node]) {

        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

// Function to count provinces
int numProvinces(vector<vector<int>>& adj, int n) {

    // Creating adjacency list
    vector<vector<int>> adjLs(n);

    // Converting adjacency matrix into adjacency list
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
            }
        }
    }

    vector<int> vis(n, 0);

    int cnt = 0;

    // Count connected components
    for(int i = 0; i < n; i++) {

        if(!vis[i]) {
            cnt++;

            dfs(i, adjLs, vis);
        }
    }

    return cnt;
}

int main() {

    int n = 6;

    /*
            0 -------- 1
            |          |
            |          |
            2          3


            4 -------- 5

        Province 1: {0, 1, 2, 3}
        Province 2: {4, 5}

        Total Provinces = 2
    */

    // Adjacency Matrix
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    int ans = numProvinces(adj, n);

    cout << "Number of Provinces: " << ans;

    return 0;
}

/*
TC: O(N^2) + O(N + E)
- Converting adjacency matrix to list: O(N^2)
- DFS traversal: O(N + E)

Overall TC: O(N^2)

SC: O(N + E)
- Adjacency list: O(N + E)
- Visited array: O(N)
- Recursive stack: O(N) in worst case
*/
