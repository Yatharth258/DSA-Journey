//Boundary Traversal in Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Check if node is a leaf
bool isLeaf(Node* root) {

    if(root->left == NULL && root->right == NULL)
        return true;

    return false;
}

// Add left boundary (excluding leaf nodes)
void addLeftBoundary(Node* root, vector<int>& res) {

    Node* cur = root->left;

    while(cur) {

        if(!isLeaf(cur))
            res.push_back(cur->data);

        if(cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// Add right boundary (excluding leaf nodes)
void addRightBoundary(Node* root, vector<int>& res) {

    Node* cur = root->right;

    vector<int> tmp;

    while(cur) {

        if(!isLeaf(cur))
            tmp.push_back(cur->data);

        if(cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    // Reverse the right boundary
    for(int i = tmp.size() - 1; i >= 0; i--) {
        res.push_back(tmp[i]);
    }
}

// Add all leaf nodes
void addLeaves(Node* root, vector<int>& res) {

     if(root == NULL) return;

    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    if(root->left)
        addLeaves(root->left, res);

    if(root->right)
        addLeaves(root->right, res);
}

// Boundary Traversal
vector<int> printBoundary(Node* root) {

    vector<int> res;

    if(root == NULL)
        return res;

    // Add root only if it is not a leaf
    if(!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);

    addLeaves(root, res);

    addRightBoundary(root, res);

    return res;
}

int main() {

    // Creating the binary tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);

    /*
                  1
                /   \
               2     3
              / \   / \
             4   5 6   7
                / \ / \
               8  9 10 11
    */

    vector<int> ans = printBoundary(root);

    cout << "Boundary Traversal: ";

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited at most once.

Space Complexity: O(H)

Recursion stack for leaf traversal.
Temporary vector stores right boundary nodes.

Overall auxiliary space: O(N) in worst case.
Output vector is O(N).
*/