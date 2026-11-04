//find the diameter of binary tree
//diameter can be defined as the longest distance between any two nodes
//the path need not necessarily to be passed from root

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

// Calculate Diameter
int height(Node* node, int& diameter) {

    if(node == NULL)
        return 0;

    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node* root) {

    int diameter = 0;

    height(root, diameter);

    return diameter;
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

    int diameter = diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << diameter << endl;

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited exactly once.

Space Complexity: O(H)

H = height of the tree (recursion stack).

Balanced Tree: O(log N)
Skewed Tree: O(N)
*/