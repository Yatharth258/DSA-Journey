//Longest BST inside the binary tree

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class NodeValue {
public:
    int maxNode;
    int minNode;
    int maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeValue largestBSTSubtreeHelper(TreeNode* root) {

    // Empty tree is a BST of size 0
    if (root == NULL) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // Get information from left and right subtrees
    NodeValue left = largestBSTSubtreeHelper(root->left);
    NodeValue right = largestBSTSubtreeHelper(root->right);

    // Check if current subtree is a valid BST
    if (left.maxNode < root->val && root->val < right.minNode) {

        return NodeValue(
            min(root->val, left.minNode),
            max(root->val, right.maxNode),
            left.maxSize + right.maxSize + 1
        );
    }

    // Invalid BST: make it impossible for the parent to be valid
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
}

int main() {

    /*
              10
             /  \
            5    15
           / \     \
          1   8     7
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);

    root->right->right = new TreeNode(7);

    cout << "Largest BST Subtree Size: "
         << largestBSTSubtree(root);

    return 0;
}

/*
Time Complexity: O(N)
Every node is visited exactly once.

Space Complexity: O(H)
Recursive stack, where H is the height of the tree.
*/