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

// Inorder Traversal
// Left -> Root -> Right
vector<int> inorderTraversal(Node* root) {

    stack<Node*> st;
    Node* node = root;

    vector<int> inorder;

    while(true) {

        if(node != NULL) {

            st.push(node);
            node = node->left;
        }

        else {

            if(st.empty() == true)
                break;

            node = st.top();
            st.pop();

            inorder.push_back(node->data);

            node = node->right;
        }
    }

    return inorder;
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

    vector<int> inorder = inorderTraversal(root);

    cout << "Inorder Traversal: ";

    for(int i = 0; i < inorder.size(); i++) {
        cout << inorder[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited once.

Space Complexity: O(H)

H = height of the tree.

In the worst case, H = N,
so worst-case space complexity is O(N).
*/