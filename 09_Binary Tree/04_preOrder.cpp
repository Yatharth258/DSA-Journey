//Pre order traversal without using recursion 

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Preorder Traversal
// Root -> Left -> Right
vector<int> preorderTraversal(Node* root) {

    vector<int> preorder;

    if(root == NULL)
        return preorder;

    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {

        root = st.top();
        st.pop();

        preorder.push_back(root->data);

        // Push right first
        if(root->right != NULL)
            st.push(root->right);

        // Push left second
        if(root->left != NULL)
            st.push(root->left);
    }

    return preorder;
}

int main() {

    // Creating the binary tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    vector<int> preorder = preorderTraversal(root);

    cout << "Preorder Traversal: ";

    for(int i = 0; i < preorder.size(); i++) {
        cout << preorder[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
Time Complexity: O(N)

We visit every node exactly once.

Space Complexity: O(N)

Stack can contain O(N) nodes in the worst case.
The preorder vector also stores O(N) elements.
*/