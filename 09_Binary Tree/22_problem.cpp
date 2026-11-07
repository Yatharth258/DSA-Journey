//Maximum width of a Binary Tree


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

int widthOfBinaryTree(Node* root) {

    if(root == NULL) return 0;

    int ans = 0;

    queue<pair<Node*, long long>> q;

    q.push({root, 0});

    while(!q.empty()) {

        int size = q.size();

        long long min = q.front().second;

        long long first, last;

        for(int i = 0; i < size; i++) {

            long long cur_id = q.front().second - min;

            Node* node = q.front().first;
            q.pop();

            if(i == 0) first = cur_id;

            if(i == size-1) last = cur_id;

            if(node->left) {
                q.push({node->left, cur_id*2+1});
            }

            if(node->right) {
                q.push({node->right, cur_id*2+2});
            }
        }

        // Width of current level
        ans = max(ans, (int)(last-first+1));
    }

    return ans;
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->right->right->right = new Node(9);

    int ans = widthOfBinaryTree(root);

    cout << "Maximum Width: " << ans;

    return 0;
}
