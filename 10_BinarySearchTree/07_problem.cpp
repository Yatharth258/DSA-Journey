//Least common ancestar in BST


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


// Lowest Common Ancestor in BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == NULL) return NULL;

    int curr = root->val;

    if(curr < p->val && curr < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    if(curr > p->val && curr > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    return root;
}


// Main function
int main() {

    // Manually constructed BST
    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Selecting p and q from the existing tree
    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    if(ans != NULL) {
        cout << "Lowest Common Ancestor: " << ans->val;
    }
    else {
        cout << "LCA not found";
    }

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

O(H)

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(H) due to recursive stack.

--------------------------------------------------
*/
