//Preorder | Inorder | Postorder 
//All three traversal in the single flow 

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

// Preorder, Inorder and Postorder using one stack
void preInPostTraversal(Node* root) {

    vector<int> pre, in, post;

    if(root == NULL)
        return;

    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty()) {

        auto it = st.top();
        st.pop();

        // This is part of Preorder
        // Increment 1 to 2
        // Push the left side of the tree

        if(it.second == 1) {

            pre.push_back(it.first->data);

            it.second++;

            st.push(it);

            if(it.first->left != NULL)
                st.push({it.first->left, 1});
        }

        // This is part of Inorder
        // Increment 2 to 3
        // Push the right side

        else if(it.second == 2) {

            in.push_back(it.first->data);

            it.second++;

            st.push(it);

            if(it.first->right != NULL)
                st.push({it.first->right, 1});
        }

        // This is part of Postorder
        // Don't push it back again

        else {

            post.push_back(it.first->data);
        }
    }

    // Printing all three traversals

    cout << "Preorder: ";
    for(int i = 0; i < pre.size(); i++)
        cout << pre[i] << " ";

    cout << endl;

    cout << "Inorder: ";
    for(int i = 0; i < in.size(); i++)
        cout << in[i] << " ";

    cout << endl;

    cout << "Postorder: ";
    for(int i = 0; i < post.size(); i++)
        cout << post[i] << " ";

    cout << endl;
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

    preInPostTraversal(root);

    return 0;
}

/*
Time Complexity: O(N)

Every node is processed exactly 3 times:
1. Preorder
2. Inorder
3. Postorder

Therefore, TC = O(3N) = O(N).

Space Complexity: O(N)

Stack can store O(N) elements in the worst case.
Three traversal vectors together also store O(N) elements.
*/