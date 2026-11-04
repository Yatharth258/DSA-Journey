//check for Balanced binary tree
// condition : 
// |Height(Left)-Height(Right)| <=1

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

int height(Node* root) {

    if(root == NULL)
        return 0;

    int lh = height(root->left);

    if(lh == -1)
        return -1;

    int rh = height(root->right);

    if(rh == -1)
        return -1;

    if(abs(lh - rh) > 1)
        return -1;

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

    int depth = height(root);

    if(depth==-1){
        cout<<"The given binary tree is not balanced";
    }else{
        cout<<"The given binary tree is balanced ";
    }

    return 0;
}

/*
Time Complexity: O(N)
Every node is visited exactly once.

Space Complexity: O(H)
Recursion stack.

Worst case: O(N)
Balanced tree: O(log N)
*/










bool isBalanced(Node* root) {

    if(root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

// TC	O(N²) worst case
// SC	O(H), worst case O(N)