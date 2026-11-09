//Ceil and Floor of a certain key(user input) in a BST
//ceil would be a smallest value that is greter than or just equal to that key
//floor would be a greatest value that is less than or just equal to that key




#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// Find Ceil in BST (smallest value >= key)
int findCeil(TreeNode* root, int key) {

    int ceil = -1;

    while(root) {

        if(root->data == key) {
            ceil = root->data;
            return ceil;
        }

        if(key > root->data) {
            root = root->right;
        }

        else {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}


// Find Floor in BST (largest value <= key)
int findFloor(TreeNode* root, int key) {

    int floor = -1;

    while(root) {

        if(root->data == key) {
            floor = root->data;
            return floor;
        }

        if(key < root->data) {
            root = root->left;
        }

        else {
            floor = root->data;
            root = root->right;
        }
    }

    return floor;
}


// Main function
int main() {

    // Manually constructed BST
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int key;

    cout << "Enter key: ";
    cin >> key;

    cout << "Ceil: " << findCeil(root, key) << endl;

    cout << "Floor: " << findFloor(root, key) << endl;

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

findCeil() = O(H)
findFloor() = O(H)

Balanced BST = O(log N)
Skewed BST = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

Both functions use O(1) auxiliary space.

H = Height of BST.
N = Number of nodes.
--------------------------------------------------
*/
