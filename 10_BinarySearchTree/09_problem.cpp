//Inorder Successor/Predecessor in BST



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


// Find Inorder Successor in BST
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

    TreeNode* successor = NULL;

    while(root != NULL) {

        if(p->val >= root->val) {
            root = root->right;
        }

        else {
            successor = root;
            root = root->left;
        }
    }

    return successor;
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

    // Given node p (value = 6)
    TreeNode* p = root->left->right;

    TreeNode* ans = inorderSuccessor(root, p);

    if(ans != NULL) {
        cout << "Inorder Successor: " << ans->val;
    }
    else {
        cout << "Inorder Successor does not exist";
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

O(1)

Iterative approach uses constant auxiliary space.

--------------------------------------------------
*/