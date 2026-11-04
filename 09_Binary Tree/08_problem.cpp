//Find out the maximum depth of the tree

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

// Maximum Depth of Binary Tree
int maxDepth(Node* root) {

    if(root == NULL)
        return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
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

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    int depth = maxDepth(root);

    cout << "Maximum Depth: " << depth << endl;

    return 0;
}

/*
Time Complexity: O(N)

We visit every node exactly once.

Space Complexity: O(H)

H = height of the tree (recursion stack).

Balanced Tree: O(log N)
Worst Case (Skewed Tree): O(N)
*/