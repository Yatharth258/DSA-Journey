//children sum property in Binary tree
//condition:
//node->val = left->val + right->val


#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Children Sum Property
void changeTree(BinaryTreeNode* root) {

    if(root == NULL) return;

    int child = 0;

    if(root->left) {
        child += root->left->data;
    }

    if(root->right) {
        child += root->right->data;
    }

    if(child >= root->data) {
        root->data = child;
    }
    else {
        if(root->left) {
            root->left->data = root->data;
        }
        else if(root->right) {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;

    if(root->left) {
        tot += root->left->data;
    }

    if(root->right) {
        tot += root->right->data;
    }

    if(root->left || root->right) {
        root->data = tot;
    }
}

// Inorder traversal to print the tree
void inorder(BinaryTreeNode* root) {

    if(root == NULL) return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Main function
int main() {

    BinaryTreeNode* root = new BinaryTreeNode(40);

    root->left = new BinaryTreeNode(10);
    root->right = new BinaryTreeNode(20);

    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(5);

    root->right->left = new BinaryTreeNode(30);
    root->right->right = new BinaryTreeNode(40);

    cout << "Before Children Sum Property: ";
    inorder(root);

    changeTree(root);

    cout << "\nAfter Children Sum Property: ";
    inorder(root);

    return 0;
}

/*
Time Complexity: O(N)

Space Complexity: O(H)

N = Total number of nodes.
H = Height of the binary tree.

- Every node is visited once.
- Recursive call stack takes O(H) space.
*/
