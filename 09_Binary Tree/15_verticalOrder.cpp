//Vertical order traversal in an binary tree


#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Vertical Traversal
vector<vector<int>> verticalTraversal(Node* root) {

    // Map: vertical -> level -> sorted nodes
    map<int, map<int, multiset<int>>> nodes;

    // Queue: node -> {vertical, level}
    queue<pair<Node*, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while(!todo.empty()) {

        auto p = todo.front();
        todo.pop();

        Node* node = p.first;

        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(node->data);

        if(node->left) {
            todo.push({node->left, {x - 1, y + 1}});
        }

        if(node->right) {
            todo.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    // Traverse columns
    for(auto p : nodes) {

        vector<int> col;

        // Traverse levels
        for(auto q : p.second) {

            // Add sorted nodes
            for(auto val : q.second) {
                col.push_back(val);
            }
        }

        ans.push_back(col);
    }

    return ans;
}

// Main function
int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    
    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    vector<vector<int>> ans = verticalTraversal(root);

    cout << "Vertical Traversal: " << endl;

    for(auto col : ans) {
        for(auto node : col) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity: O(N log N)
Space Complexity: O(N)

N = Total number of nodes.

- Map and multiset insertion take O(log N).
- BFS visits every node once.
- Queue, map and result storage take O(N) space.
*/
