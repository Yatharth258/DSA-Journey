
#include <bits/stdc++.h>
using namespace std;

// BFS Function
vector<int> bfs(int n, vector<vector<int>>& adj) {

    vector<int> ans;
    vector<int> vis(n, 0);

    queue<int> q;

    // Starting BFS from node 0
    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        // Visit all adjacent nodes
        for(auto it : adj[node]) {

            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
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

    // Performing BFS
    vector<int> ans = bfs(n, adj);

    // Printing BFS traversal
    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}

/*
Time Complexity: O(N + E)
- Every node is visited once: O(N)
- Every edge is explored: O(E)

Space Complexity: O(N)
- Visited array: O(N)
- Queue: O(N)
- Answer array: O(N)
*/
