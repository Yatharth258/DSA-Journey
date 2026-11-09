// Binary Search Tree (BST)
// A Binary Search Tree (BST) is a special type of Binary Tree in which every node follows a specific ordering property.

// Properties of BST
// For every node:
// - Left Subtree: Contains values smaller than the current node.
// - Right Subtree: Contains values greater than the current node.
// - Both left and right subtrees must also be BSTs.
// - Generally, duplicate values are not allowed (depends on implementation).




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


// Search in BST
TreeNode* searchBST(TreeNode* root, int val) {

    while(root != NULL && root->val != val) {

        root = val < root->val ? root->left : root->right;
    }

    return root;
}


// Main function
int main() {

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;

    TreeNode* ans = searchBST(root, val);

    if(ans != NULL) {
        cout << "Value found: " << ans->val;
    }
    else {
        cout << "Value not found";
    }

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

O(H)

H = Height of BST.

Average case (balanced BST) = O(log N)
Worst case (skewed BST) = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(1)

Iterative approach uses constant auxiliary space.

--------------------------------------------------
*/
