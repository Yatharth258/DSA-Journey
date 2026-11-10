//Find the kth largest elemnt and smallest elemnt 


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


// Function 1: K-th Smallest using Morris Inorder
int kthSmallest(TreeNode* root, int k) {

    int cnt = 0;

    TreeNode* cur = root;

    while(cur != NULL) {

        if(cur->left == NULL) {

            cnt++;

            if(cnt == k) return cur->val;

            cur = cur->right;
        }

        else {

            TreeNode* prev = cur->left;

            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {

                prev->right = cur;
                cur = cur->left;
            }

            else {

                prev->right = NULL;

                cnt++;

                if(cnt == k) return cur->val;

                cur = cur->right;
            }
        }
    }

    return -1;
}


// Function 2: K-th Largest using Morris Reverse Inorder
int kthLargest(TreeNode* root, int k) {

    int cnt = 0;

    TreeNode* cur = root;

    while(cur != NULL) {

        if(cur->right == NULL) {

            cnt++;

            if(cnt == k) return cur->val;

            cur = cur->left;
        }

        else {

            TreeNode* prev = cur->right;

            while(prev->left && prev->left != cur) {
                prev = prev->left;
            }

            if(prev->left == NULL) {

                prev->left = cur;
                cur = cur->right;
            }

            else {

                prev->left = NULL;

                cnt++;

                if(cnt == k) return cur->val;

                cur = cur->left;
            }
        }
    }

    return -1;
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

    int k = 3;

    cout << k << "-th Smallest Element: "
         << kthSmallest(root, k) << endl;

    cout << k << "-th Largest Element: "
         << kthLargest(root, k) << endl;

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

kthSmallest() = O(N)
kthLargest()  = O(N)

Both use Morris Traversal.

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(1) Auxiliary Space.

No recursion or stack is used.

--------------------------------------------------
*/
