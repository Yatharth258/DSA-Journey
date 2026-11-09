//Count complte binary tree

// Given the root of a complete binary tree, return the number of the nodes in the tree.
// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can
// have between 1 and 2^h nodes inclusive at the last level h
// Design an algorithm that runs in less than 0(n) time complexity.


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


// Function 1: Find height of leftmost path
int findHeightLeft(TreeNode* node) {

    int hght = 0;

    while(node) {
        hght++;
        node = node->left;
    }

    return hght;
}


// Function 2: Find height of rightmost path
int findHeightRight(TreeNode* node) {

    int hght = 0;

    while(node) {
        hght++;
        node = node->right;
    }

    return hght;
}


// Function 3: Count total nodes
int countNodes(TreeNode* root) {

    if(root == NULL) return 0;

    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    // If left and right heights are equal,
    // the tree is a perfect binary tree
    if(lh == rh) return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Function 4: Construct binary tree using level order

//This part is just for understading like how you will construct tree in level order wise (if we take input form user)
//This function has nothing to do with the question 
TreeNode* constructTree(vector<int> arr) {

    if(arr.size() == 0 || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()) {

        TreeNode* node = q.front();
        q.pop();

        if(arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}


// Main function
int main() {

    // -1 represents NULL
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    TreeNode* root = constructTree(arr);

    cout << "Total nodes: " << countNodes(root);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

findHeightLeft()  = O(log N)
findHeightRight() = O(log N)

countNodes():

If the subtree is perfect:
    O(log N)

Otherwise:
    Recursively processes smaller subtrees.

Overall TC = O(log^2 N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

Recursive stack = O(log N)
Tree construction = O(N)

Auxiliary SC (excluding tree) = O(log N)

--------------------------------------------------
*/
