//Validate a BST
//check wether given binary tree is BST or not


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


// Function 1: Validate BST
bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {

    if(root == NULL) return true;

    if(root->val >= maxVal || root->val <= minVal) {
        return false;
    }

    return isValidBST(root->left, minVal, root->val)
        && isValidBST(root->right, root->val, maxVal);
}


// Function 2: Wrapper function
bool isValidBST(TreeNode* root) {

    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}


// Main function
int main() {

    // Manually constructed BST
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    if(isValidBST(root)) {
        cout << "Valid BST";
    }
    else {
        cout << "Invalid BST";
    }

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

O(N)

Every node is visited exactly once.

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(H)

Due to recursive call stack.

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
*/
