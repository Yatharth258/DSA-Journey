//find wether the given binary tree is symmetrical or not


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

bool isSymmetricHelp(Node* left, Node* right) {

    if(left == NULL || right == NULL) {
        return left == right;
    }

    if(left->val != right->val) return false;

    return isSymmetricHelp(left->left, right->right) &&
           isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(Node* root) {

    return root == NULL || isSymmetricHelp(root->left, root->right);

}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(isSymmetric(root)) {
        cout << "Tree is Symmetric";
    }
    else {
        cout << "Tree is not Symmetric";
    }

    return 0;
}

// TC and SC O(N)