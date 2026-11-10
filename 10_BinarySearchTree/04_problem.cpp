//Delete a node in a binary search tree


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


// Find rightmost node of a subtree
TreeNode* findLastRight(TreeNode* root) {

    if(root->right == NULL) {
        return root;
    }

    return findLastRight(root->right);
}


// Helper function to delete a node
TreeNode* helper(TreeNode* root) {

    if(root->left == NULL) {
        return root->right;
    }

    else if(root->right == NULL) {
        return root->left;
    }

    TreeNode* rightChild = root->right;

    TreeNode* lastRight = findLastRight(root->left);

    lastRight->right = rightChild;

    return root->left;
}


// Delete node from BST
TreeNode* deleteNode(TreeNode* root, int key) {

    if(root == NULL) {
        return NULL;
    }

    if(root->val == key) {
        return helper(root);
    }

    TreeNode* dummy = root;

    while(root != NULL) {

        if(root->val > key) {

            if(root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            }

            else {
                root = root->left;
            }
        }

        else {

            if(root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            }

            else {
                root = root->right;
            }
        }
    }

    return dummy;
}


// Inorder traversal to display BST
void inorder(TreeNode* root) {

    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
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

    int key;

    cout << "Enter key to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "BST after deletion (Inorder): ";
    inorder(root);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

deleteNode() = O(H)

helper() = O(H) in worst case
findLastRight() = O(H)

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(H) due to recursive findLastRight().

--------------------------------------------------
*/
