//Detect cycle in an undirected graph using BFS


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool detect(int src, vector<int> adj[], vector<int>& vis) {

        vis[src] = 1;

        queue<pair<int, int>> q;
        q.push({src, -1});

        while(!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for(auto adjacentNode : adj[node]) {

                if(!vis[adjacentNode]) {

                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});

                }
                else if(parent != adjacentNode) {

                    return true;
                }
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

                if(detect(i, adj, vis)) {
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

    // Edges of the undirected graph
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
- In an undirected graph, every edge appears twice.

Space Complexity: O(V)

- Visited array: O(V).
- BFS queue: O(V) in the worst case.
- Auxiliary Space: O(V).
*/
