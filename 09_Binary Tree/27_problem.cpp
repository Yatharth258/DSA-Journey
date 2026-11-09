//  Constrcut a unique binary tree based on on the some data given :
//Note:we are assimng all the elements of the nodes are unique/diffreent (its helps in hashing)
// A)Construct a binary tree using inorder and preorder traversal given 




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


// Function 1: Build tree recursively
TreeNode* buildTree(
    vector<int>& preorder,
    int preStart,
    int preEnd,
    vector<int>& inorder,
    int inStart,
    int inEnd,
    map<int, int>& inMap
) {

    if(preStart > preEnd || inStart > inEnd) return NULL;

    // Create root using preorder
    TreeNode* root = new TreeNode(preorder[preStart]);

    // Find root position in inorder
    int inRoot = inMap[root->val];

    // Calculate number of nodes in left subtree
    int numsLeft = inRoot - inStart;

    // Build left subtree
    root->left = buildTree(
        preorder,
        preStart + 1,
        preStart + numsLeft,
        inorder,
        inStart,
        inRoot - 1,
        inMap
    );

    // Build right subtree
    root->right = buildTree(
        preorder,
        preStart + numsLeft + 1,
        preEnd,
        inorder,
        inRoot + 1,
        inEnd,
        inMap
    );

    return root;
}


// Function 2: Main buildTree function
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    map<int, int> inMap;

    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    TreeNode* root = buildTree(
        preorder,
        0,
        preorder.size() - 1,
        inorder,
        0,
        inorder.size() - 1,
        inMap
    );

    return root;
}


// Function to print inorder traversal
void inorderTraversal(TreeNode* root) {

    if(root == NULL) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


// Main function
int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder Traversal: ";
    //we are printing again the inorder traversal at the end becuase tp verify the constructed tree is correct or not 
    inorderTraversal(root);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

1. Creating inMap = O(N log N)
   Because we are using map.

2. Recursive buildTree = O(N log N)
   Each node is processed once and map lookup
   takes O(log N).

Overall TC = O(N log N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

1. inMap = O(N)
2. Recursive stack = O(H)
3. Constructed tree = O(N)

Auxiliary SC = O(N + H) = O(N)

H = Height of the tree.

--------------------------------------------------
*/
