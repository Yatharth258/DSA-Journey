//Two Sum in BST


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


// Push nodes according to traversal direction
void pushAll(TreeNode* node, stack<TreeNode*>& st, bool reverse) {

    while(node != NULL) {

        st.push(node);

        if(reverse == true) {
            node = node->right;
        }

        else {
            node = node->left;
        }
    }
}


// Return next element according to direction
int next(stack<TreeNode*>& st, bool reverse) {

    TreeNode* tmpNode = st.top();
    st.pop();

    if(reverse == true) {
        pushAll(tmpNode->left, st, true);
    }

    else {
        pushAll(tmpNode->right, st, false);
    }

    return tmpNode->val;
}


// Check whether stack has next element
bool hasNext(stack<TreeNode*>& st) {

    return !st.empty();
}


// Find two nodes whose sum equals k
bool findTarget(TreeNode* root, int k) {

    if(root == NULL) return false;

    stack<TreeNode*> l;
    stack<TreeNode*> r;

    // Normal Inorder (Smallest first)
    pushAll(root, l, false);

    // Reverse Inorder (Largest first)
    pushAll(root, r, true);

    int i = next(l, false);
    int j = next(r, true);

    while(i < j) {

        if(i + j == k) {
            return true;
        }

        else if(i + j < k) {
            if(!hasNext(l)) break;
            i = next(l, false);
        }

        else {
            if(!hasNext(r)) break;
            j = next(r, true);
        }
    }

    return false;
}


// Main function
int main() {

    // Manually constructed BST
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    int k = 9;

    if(findTarget(root, k)) {
        cout << "Pair exists whose sum is " << k;
    }

    else {
        cout << "No pair exists whose sum is " << k;
    }

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

pushAll() = O(H)

Each node is processed at most once by each iterator.

findTarget() = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

Two stacks = O(H)

Overall Auxiliary SC = O(H)

H = Height of BST.

--------------------------------------------------
*/
