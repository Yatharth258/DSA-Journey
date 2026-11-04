//find wether the given two binary tree are identical or not

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

// Check if both trees are identical
bool isSameTree(Node* p, Node* q) {

    // Both nodes are NULL
    if(p == NULL || q == NULL) {
        return (p == q);
    }

    return (p->data == q->data)
           && isSameTree(p->left, q->left)
           && isSameTree(p->right, q->right);
}

int main() {

    // Creating first binary tree
    Node* p = new Node(1);

    p->left = new Node(2);
    p->right = new Node(3);

    /*
              1
             / \
            2   3
    */

    // Creating second binary tree
    Node* q = new Node(1);

    q->left = new Node(2);
    q->right = new Node(3);

    /*
              1
             / \
            2   3
    */

    bool ans = isSameTree(p, q);

    if(ans)
        cout << "Both trees are identical";
    else
        cout << "Both trees are not identical";

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited once (assuming both trees
have the same structure and size).

Space Complexity: O(H)

H = height of the recursion stack.

Worst Case: O(N)
Balanced Tree: O(log N)
*/