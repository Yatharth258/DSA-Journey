//Lowest Common Ancestor


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {

    // Base case
    if(root == NULL || root == p || root == q) {
        return root;
    }

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    // Result
    if(left == NULL) {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else {
        return root;
    }
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* p = root->left->left;   // Node 4
    Node* q = root->left->right;  // Node 5

    Node* ans = lowestCommonAncestor(root, p, q);

    if(ans != NULL) {
        cout << "Lowest Common Ancestor: " << ans->val;
    }
    else {
        cout << "LCA not found";
    }

    return 0;
}

// Complexity
// - Time Complexity: O(N) – Each node is visited at most once.
// - Space Complexity: O(H) – Recursive stack.