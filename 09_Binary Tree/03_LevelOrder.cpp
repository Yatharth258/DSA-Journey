//Level order traversal 

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

// Level Order Traversal
vector<vector<int>> levelOrder(Node* root) {

    vector<vector<int>> ans;

    if(root == NULL)
        return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {

        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++) {

            Node* node = q.front();
            q.pop();

            level.push_back(node->data);

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);
        }

        ans.push_back(level);
    }

    return ans;
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

    vector<vector<int>> ans = levelOrder(root);

    cout << "Level Order Traversal:" << endl;

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

We visit every node exactly once.

Space Complexity: O(N)

Queue can contain up to O(N) nodes in the worst case.
The answer vector also stores O(N) elements.
*/