//Insert the given node in the binary search tree


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


// Insert into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {

    if(root == NULL) return new TreeNode(val);

    TreeNode* cur = root;

    while(true) {

        if(cur->val <= val) {

            if(cur->right != NULL) {
                cur = cur->right;
            }

            else {
                cur->right = new TreeNode(val);
                break;
            }
        }

        else {

            if(cur->left != NULL) {
                cur = cur->left;
            }

            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }

    return root;
}


// Inorder Traversal to display BST
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

    int val;

    cout << "Enter value to insert: ";
    cin >> val;

    root = insertIntoBST(root, val);

    cout << "BST after insertion (Inorder): ";
    inorder(root);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

insertIntoBST() = O(H)

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

insertIntoBST() = O(1)

Iterative approach uses constant auxiliary space.

--------------------------------------------------
*/
