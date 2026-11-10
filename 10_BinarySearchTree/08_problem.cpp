//Construct a binary tree from the given preorder traversal




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


// Function 1: Build BST recursively
TreeNode* build(vector<int>& A, int& i, long long bound) {

    if(i == A.size() || A[i] > bound) {
        return NULL;
    }

    TreeNode* root = new TreeNode(A[i++]);

    root->left = build(A, i, root->val);

    root->right = build(A, i, bound);

    return root;
}


// Function 2: Main BST construction function
TreeNode* bstFromPreorder(vector<int>& A) {

    int i = 0;

    return build(A, i, LLONG_MAX);
}


// Inorder traversal to verify BST
void inorder(TreeNode* root) {

    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


// Main function
int main() {

    vector<int> A = {8, 5, 1, 7, 10, 12};

    TreeNode* root = bstFromPreorder(A);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

O(N)

Each element is processed exactly once.

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(H) due to recursive stack.

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
*/
