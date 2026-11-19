//Cycle detection using DFS Algorithm


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {

        vis[node] = 1;

        for(auto adjacentNode : adj[node]) {

            if(!vis[adjacentNode]) {

                if(dfs(adjacentNode, node, vis, adj) == true) {
                    return true;
                }

            }
            else if(adjacentNode != parent) {

                return true;
            }
        }

        return false;
    }

public:

    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {

            if(!vis[i]) {

                if(dfs(i, -1, vis, adj) == true) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    int V = 5;

    vector<int> adj[V];

    // Undirected edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1);
    adj[1].push_back(4);

    Solution obj;

    if(obj.isCycle(V, adj)) {
        cout << "Cycle detected" << endl;
    }
    else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}

/*
Time Complexity: O(V + 2E) = O(V + E)

- Every vertex is visited once.
- Every adjacency list entry is traversed once.
- Every undirected edge appears twice.

Space Complexity: O(V)

- Visited array: O(V).
- Recursive DFS stack: O(V) in the worst case.
- Auxiliary Space: O(V).
*/


