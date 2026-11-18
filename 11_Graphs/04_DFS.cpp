
#include <bits/stdc++.h>
using namespace std;

// DFS Function
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans) {

    // Mark current node as visited
    vis[node] = 1;

    // Store node in answer
    ans.push_back(node);

    // Traverse all adjacent nodes
    for(auto it : adj[node]) {

        if(!vis[it]) {
            dfs(it, adj, vis, ans);
        }
    }
}

int main() {

    int n = 6;

    /*
             0
            / \
           1   2
          / \   \
         3   4   5

        Edges:
        0 - 1
        0 - 2
        1 - 3
        1 - 4
        2 - 5
    */

    // Creating adjacency list
    vector<vector<int>> adj(n);

    // Adding edges (Undirected Graph)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[2].push_back(5);
    adj[5].push_back(2);

    // Visited array
    vector<int> vis(n, 0);

    // Answer vector
    vector<int> ans;

    // Starting DFS from node 0
    dfs(0, adj, vis, ans);

    // Printing DFS traversal
    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}

/*
TC: O(N + E)
- Every node is visited once: O(N)
- Every edge is explored at most twice: O(2E)

SC: O(N)
- Visited array: O(N)
- Answer vector: O(N)
- Recursive stack: O(N) in worst case
*/
