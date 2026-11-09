//Flatten a binary tree into a linked list


    //       1                                            
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    //     |
    //     |
    // after coversion

    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    //        \
    //         5
    //          \
    //           6

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


// Create a copy of the original tree
TreeNode* copyTree(TreeNode* root) {

    if(root == NULL) return NULL;

    TreeNode* newNode = new TreeNode(root->val);

    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}


// Method 1: Using Recursion (Reverse Preorder)
void flattenRecursive(TreeNode* root, TreeNode*& prev) {

    if(root == NULL) return;

    flattenRecursive(root->right, prev);
    flattenRecursive(root->left, prev);

    root->right = prev;
    root->left = NULL;

    prev = root;
}


// Method 2: Using Stack
void flattenStack(TreeNode* root) {

    if(root == NULL) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {

        TreeNode* cur = st.top();
        st.pop();

        if(cur->right) st.push(cur->right);

        if(cur->left) st.push(cur->left);

        if(!st.empty()) {
            cur->right = st.top();
        }

        cur->left = NULL;
    }
}


// Method 3: Using Morris Traversal
void flattenMorris(TreeNode* root) {

    TreeNode* cur = root;

    while(cur != NULL) {

        if(cur->left != NULL) {

            TreeNode* prev = cur->left;

            while(prev->right != NULL) {
                prev = prev->right;
            }

            prev->right = cur->right;

            cur->right = cur->left;

            cur->left = NULL;
        }

        cur = cur->right;
    }
}


// Print flattened linked list
vector<int> printList(TreeNode* root) {

    vector<int> ans;

    while(root) {

        // Check if left pointer is NULL
        if(root->left != NULL) {
            cout << "Error: Left pointer is not NULL!";
            return {};
        }

        ans.push_back(root->val);
        root = root->right;
    }

    for(auto it : ans) {
        cout << it << " ";
    }

    cout << endl;

    return ans;
}


// Main function
int main() {

    // Original tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);


    // Create three separate copies
    TreeNode* root1 = copyTree(root);
    TreeNode* root2 = copyTree(root);
    TreeNode* root3 = copyTree(root);


    // Apply all three approaches
    TreeNode* prev = NULL;

    flattenRecursive(root1, prev);

    flattenStack(root2);

    flattenMorris(root3);


    // Print results
    cout << "Recursion: ";
    vector<int> ans1 = printList(root1);

    cout << "Stack:     ";
    vector<int> ans2 = printList(root2);

    cout << "Morris:    ";
    vector<int> ans3 = printList(root3);


    // Compare all three results
    cout << "\nComparison: ";

    if(ans1 == ans2 && ans2 == ans3) {
        cout << "All three approaches give the same result!";
    }
    else {
        cout << "Results are different!";
    }

    cout << endl;

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

1. copyTree() = O(N)

2. Recursive approach:
   O(N)

3. Stack approach:
   O(N)

4. Morris approach:
   O(N)

5. Comparing results:
   O(N)

Overall TC = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

1. Three tree copies = O(N)
2. Recursive stack = O(H)
3. Stack approach = O(N)
4. Morris approach = O(1)
5. Output vectors = O(N)

Overall SC = O(N)

Note:
The above overall complexity includes the
three copies and output storage.

Individual auxiliary space:
Recursion = O(H)
Stack = O(N)
Morris = O(1)

--------------------------------------------------
*/
