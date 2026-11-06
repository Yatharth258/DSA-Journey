//Top view of a binary tree


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

// Top View of Binary Tree
vector<int> topView(Node* root) {

    vector<int> ans;

    if(root == NULL) return ans;

    // Map: vertical line -> first node
    map<int, int> mpp;

    // Queue: node -> vertical line
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty()) {

        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int line = it.second;

        // Store only the first node at each vertical line
        if(mpp.find(line) == mpp.end()) {
            mpp[line] = node->data;
        }

        if(node->left != NULL) {
            q.push({node->left, line - 1});
        }

        if(node->right != NULL) {
            q.push({node->right, line + 1});
        }
    }

    // Store nodes from left to right
    for(auto it : mpp) {
        ans.push_back(it.second);
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

    vector<int> ans = topView(root);

    cout << "Top View: ";

    for(auto x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
Time Complexity: O(N log N)

Space Complexity: O(N)

N = Total number of nodes.

- BFS visits every node once.
- Map insertion/search takes O(log N).
- Queue and map can store O(N) nodes/entries.
*/
