//Print root to node path in an Binary tree


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

bool getPath(Node* root, vector<int> &arr, int x) {

    if(root == NULL) {
        return false;
    }

    arr.push_back(root->val);

    if(root->val == x) {
        return true;
    }

    if(getPath(root->left, arr, x) ||
       getPath(root->right, arr, x)) {
        return true;
    }

    arr.pop_back();

    return false;
}

vector<int> solve(Node* root, int x) {

    vector<int> arr;

    if(root == NULL) {
        return arr;
    }

    getPath(root, arr, x);

    return arr;
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int x = 5;

    vector<int> ans = solve(root, x);

    if(ans.empty()) {
        cout << "Node not found";
    }
    else {
        for(auto it : ans) {
            cout << it << " ";
        }
    }

    return 0;
}

// Complexity
// - TC: O(N) – In the worst case, we visit every node.
// - SC: O(H) – Recursive stack, excluding the output vector.