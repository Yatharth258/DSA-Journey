//Morris Traversal 
//WHY-> it have advantage in space complexity as O(1)
//code for inorder and preorder traversal using morris 


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


// Morris Inorder Traversal
vector<int> getInorder(TreeNode* root) {

    vector<int> inorder;
    TreeNode* cur = root;

    while(cur != NULL) {

        if(cur->left == NULL) {

            inorder.push_back(cur->val);
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
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }

    return inorder;
}


// Morris Preorder Traversal
vector<int> getPreorder(TreeNode* root) {

    vector<int> preorder;
    TreeNode* cur = root;

    while(cur != NULL) {

        if(cur->left == NULL) {

            preorder.push_back(cur->val);
            cur = cur->right;
        }

        else {

            TreeNode* prev = cur->left;

            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == NULL) {

                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }

            else {

                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}


// Main function
int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> in = getInorder(root);
    vector<int> pre = getPreorder(root);

    cout << "Inorder: ";
    for(auto it : in) cout << it << " ";

    cout << endl;

    cout << "Preorder: ";
    for(auto it : pre) cout << it << " ";

    return 0;
}


/*
TC:
Both traversals = O(N)

SC:
O(1) auxiliary space.
O(N) including the output vector.

N = Total number of nodes.
*/
