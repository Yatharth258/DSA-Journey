//Zig Zag / Spiral Traversal

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

// Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(Node* root) {

    vector<vector<int>> result;

    if(root == NULL)
        return result;

    queue<Node*> nodesQueue;
    nodesQueue.push(root);

    bool leftToRight = true;

    while(!nodesQueue.empty()) {

        int size = nodesQueue.size();

        vector<int> row(size);

        for(int i = 0; i < size; i++) {

            Node* node = nodesQueue.front();
            nodesQueue.pop();

            // Find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->data;

            if(node->left != NULL)
                nodesQueue.push(node->left);

            if(node->right != NULL)
                nodesQueue.push(node->right);
        }

        // After completing current level
        leftToRight = !leftToRight;

        result.push_back(row);
    }

    return result;
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

    vector<vector<int>> ans = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;

    for(int i = 0; i < ans.size(); i++) {

        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

/*
Time Complexity: O(N)

Every node is visited exactly once.

Space Complexity: O(N)

Queue can store O(N) nodes in the worst case.
Result vector also stores O(N) elements.
*/