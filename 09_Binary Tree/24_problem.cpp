//Print all the nodes at the distance k in an binary tree



#include <bits/stdc++.h>
using namespace std;

// Structure of a Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Step 1: Mark parents of every node
void markParents(TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*>& parent_track) {

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }

        if(current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

// Step 2: Find nodes at distance K
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    unordered_map<TreeNode*, TreeNode*> parent_track;

    markParents(root, parent_track);

    unordered_map<TreeNode*, bool> visited;

    queue<TreeNode*> q;

    q.push(target);
    visited[target] = true;

    int curr_level = 0;

    while(!q.empty()) {

        int size = q.size();

        if(curr_level == k) break;

        curr_level++;

        for(int i = 0; i < size; i++) {

            TreeNode* current = q.front();
            q.pop();

            // Check left child
            if(current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }

            // Check right child
            if(current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }

            // Check parent
            if(parent_track.count(current) &&
               !visited[parent_track[current]]) {

                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;

    while(!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        result.push_back(current->val);
    }

    return result;
}

// Main function
int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left;

    int k = 2;

    vector<int> ans = distanceK(root, target, k);

    cout << "Nodes at distance " << k << ": ";

    for(auto x : ans) {
        cout << x << " ";
    }

    return 0;
}

/*
Time Complexity: O(N)

Space Complexity: O(N)

N = Total number of nodes.

- First BFS (markParents): O(N)
- Second BFS (distanceK): O(N)
- Parent map, visited map and queue: O(N)
*/
