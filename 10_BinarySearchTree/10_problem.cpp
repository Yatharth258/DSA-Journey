//BST iterator



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


// Push all left-side nodes into stack
void pushAll(TreeNode* node, stack<TreeNode*>& st) {

    while(node != NULL) {
        st.push(node);
        node = node->left;
    }
}


// Check whether next smallest element exists
bool hasNext(stack<TreeNode*>& st) {

    return !st.empty();
}


// Return next smallest element
int next(stack<TreeNode*>& st) {

    TreeNode* tmpNode = st.top();

    st.pop();

    pushAll(tmpNode->right, st);

    return tmpNode->val;
}


// Main function
int main() {

    // Manually constructed BST
    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);


    stack<TreeNode*> myStack;

    // Initialize iterator
    pushAll(root, myStack);

    cout << "BST Iterator: ";

    while(hasNext(myStack)) {
        cout << next(myStack) << " ";
    }

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

pushAll() = O(H)

next() = O(1) amortized
         O(H) worst case.

hasNext() = O(1)

Overall traversal = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

O(H)

H = Height of BST.

--------------------------------------------------
*/
