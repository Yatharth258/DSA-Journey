//Post order traversal using 2 stack method

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

// Postorder Traversal
// Left -> Right -> Root
vector<int> postorderTraversal(Node* root) {

    vector<int> postorder;

    if(root == NULL)
        return postorder;

    stack<Node*> st1, st2;

    st1.push(root);

    while(!st1.empty()) {

        root = st1.top();
        st1.pop();

        st2.push(root);

        if(root->left != NULL)
            st1.push(root->left);

        if(root->right != NULL)
            st1.push(root->right);
    }

    while(!st2.empty()) {

        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
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

    vector<int> postorder = postorderTraversal(root);

    cout << "Postorder Traversal: ";

    for(int i = 0; i < postorder.size(); i++) {
        cout << postorder[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited once in st1
and once in st2.

Space Complexity: O(N)

We are using two stacks, and in the
worst case they can contain O(N) nodes.
*/