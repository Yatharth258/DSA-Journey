//B)Construct a binary tree using inorder and postorder traversal given


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
TreeNode* buildTreePostIn(
    vector<int>& inorder,
    int is,
    int ie,
    vector<int>& postorder,
    int ps,
    int pe,
    map<int, int>& hm
) {

    if(ps > pe || is > ie) return NULL;

    // Create root using postorder
    TreeNode* root = new TreeNode(postorder[pe]);

    // Find root position in inorder
    int inRoot = hm[postorder[pe]];

    // Calculate number of nodes in left subtree
    int numsLeft = inRoot - is;

    // Build left subtree
    root->left = buildTreePostIn(
        inorder,
        is,
        inRoot - 1,
        postorder,
        ps,
        ps + numsLeft - 1,
        hm
    );

    // Build right subtree
    root->right = buildTreePostIn(
        inorder,
        inRoot + 1,
        ie,
        postorder,
        ps + numsLeft,
        pe - 1,
        hm
    );

    return root;
}


// Function 2: Main buildTree function
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    if(inorder.size() != postorder.size()) return NULL;

    map<int, int> hm;

    for(int i = 0; i < inorder.size(); i++) {
        hm[inorder[i]] = i;
    }

    return buildTreePostIn(
        inorder,
        0,
        inorder.size() - 1,
        postorder,
        0,
        postorder.size() - 1,
        hm
    );
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

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);

     cout << "Inorder Traversal: ";
    //we are printing again the inorder traversal at the end becuase tp verify the constructed tree is correct or not 
    inorderTraversal(root);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

1. Creating hm = O(N log N)
   Because map insertion takes O(log N).

2. Recursive buildTreePostIn = O(N log N)
   Each node is processed once and map lookup
   takes O(log N).

Overall TC = O(N log N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

1. hm = O(N)
2. Recursive stack = O(H)
3. Constructed tree = O(N)

Auxiliary SC = O(N + H) = O(N)

H = Height of the tree.

--------------------------------------------------
*/

