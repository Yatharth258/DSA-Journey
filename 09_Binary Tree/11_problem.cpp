//find the max sum path

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

// Maximum Path Sum
int maxPathDown(Node* node, int& maxi) {

    if(node == NULL)
        return 0;

    int left = max(0, maxPathDown(node->left, maxi));
    int right = max(0, maxPathDown(node->right, maxi));

    maxi = max(maxi, left + right + node->data);

    return max(left, right) + node->data;
}

int maxPathSum(Node* root) {

    int maxi = INT_MIN;

    maxPathDown(root, maxi);

    return maxi;
}

int main() {

    // Creating the binary tree
    Node* root = new Node(-10);

    root->left = new Node(9);
    root->right = new Node(20);

    root->right->left = new Node(15);
    root->right->right = new Node(7);

    /*
              -10
             /   \
            9     20
                 /  \
                15   7
    */

    int ans = maxPathSum(root);

    cout << "Maximum Path Sum: " << ans << endl;

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited exactly once.

Space Complexity: O(H)

H = height of the tree (recursion stack).

Balanced Tree: O(log N)
Skewed Tree: O(N)
*/