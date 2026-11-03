//Post order traversal using only 1 stack

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

    stack<Node*> st;
    Node* node = root;

    while(node != NULL || !st.empty()) {

        if(node != NULL) {

            st.push(node);
            node = node->left;
        }

        else {

            Node* temp = st.top()->right;

            if(temp == NULL) {

                temp = st.top();
                st.pop();

                postorder.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right) {

                    temp = st.top();
                    st.pop();

                    postorder.push_back(temp->data);
                }
            }

            else {

                node = temp;
            }
        }
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

Every node is processed once.

Space Complexity: O(H)

H = height of the tree.

Worst case: O(N)
Balanced tree: O(log N)
*/