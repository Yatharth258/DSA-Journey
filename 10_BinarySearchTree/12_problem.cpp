//Recover the BST
//you will be given the bst , but the two nodes are wrongly placed/swapped ,you need to recover the original BST


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

void inorder(TreeNode* root, TreeNode*& first, TreeNode*& middle,
             TreeNode*& last, TreeNode*& prev) {

    if (root == NULL) return;

    inorder(root->left, first, middle, last, prev);

    // Check if current node violates BST inorder order
    if (prev != NULL && root->val < prev->val) {

        if (first == NULL) {
            first = prev;
            middle = root;
        }
        else {
            last = root;
        }
    }

    prev = root;

    inorder(root->right, first, middle, last, prev);
}

void recoverTree(TreeNode* root) {

    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;

    inorder(root, first, middle, last, prev);

    // Two non-adjacent nodes are swapped
    if (first != NULL && last != NULL) {
        swap(first->val, last->val);
    }

    // Two adjacent nodes are swapped
    else if (first != NULL && middle != NULL) {
        swap(first->val, middle->val);
    }
}

void printInorder(TreeNode* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    // Manually creating a BST with two swapped nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before recovery: ";
    printInorder(root);

    recoverTree(root);

    cout << "\nAfter recovery: ";
    printInorder(root);

    return 0;
}

/*
Time Complexity: O(N)
Space Complexity: O(H) - Recursive stack
*/

/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

Inorder Traversal = O(N)
Swapping values = O(1)

Overall TC = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(H) due to recursive call stack.

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
*/
