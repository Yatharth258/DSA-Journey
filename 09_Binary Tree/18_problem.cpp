//Finding the left/right view of a binary tree


#include <bits/stdc++.h>
using namespace std;

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

// Left View
void leftView(Node* root, int level, vector<int> &ans) {

    if(root == NULL) return;

    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    leftView(root->left, level+1, ans);
    leftView(root->right, level+1, ans);
}

// Right View
void rightView(Node* root, int level, vector<int> &ans) {

    if(root == NULL) return;

    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    rightView(root->right, level+1, ans);
    rightView(root->left, level+1, ans);
}

int main() {

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

    vector<int> leftAns;
    vector<int> rightAns;

    leftView(root, 0, leftAns);
    rightView(root, 0, rightAns);

    cout << "Left View: ";
    for(auto it : leftAns) {
        cout << it << " ";
    }

    cout << endl;

    cout << "Right View: ";
    for(auto it : rightAns) {
        cout << it << " ";
    }

    return 0;
}
