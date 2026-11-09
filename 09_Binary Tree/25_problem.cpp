//Time required to burn an entire Binary tree


#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to construct binary tree using level order
BinaryTreeNode* constructTree(vector<int> arr) {

    if(arr.size() == 0 || arr[0] == -1) return NULL;

    BinaryTreeNode* root = new BinaryTreeNode(arr[0]);

    queue<BinaryTreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()) {

        BinaryTreeNode* node = q.front();
        q.pop();

        if(arr[i] != -1) {
            node->left = new BinaryTreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1) {
            node->right = new BinaryTreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}


// Function 1: Find maximum distance (time taken to burn tree)
int findMaxDistance(
    map<BinaryTreeNode*, BinaryTreeNode*>& mpp,
    BinaryTreeNode* target
) {

    queue<BinaryTreeNode*> q;
    q.push(target);

    map<BinaryTreeNode*, int> vis;
    vis[target] = 1;

    int maxi = 0;

    while(!q.empty()) {

        int sz = q.size();
        int fl = 0;

        for(int i = 0; i < sz; i++) {

            auto node = q.front();
            q.pop();

            // Visit left child
            if(node->left && !vis[node->left]) {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }

            // Visit right child
            if(node->right && !vis[node->right]) {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }

            // Visit parent
            if(mpp[node] && !vis[mpp[node]]) {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }

        if(fl) maxi++;
    }

    return maxi;
}


// Function 2: Map parents and find target node
BinaryTreeNode* bfsToMapParents(
    BinaryTreeNode* root,
    map<BinaryTreeNode*, BinaryTreeNode*>& mpp,
    int start
) {

    queue<BinaryTreeNode*> q;
    q.push(root);

    BinaryTreeNode* res = NULL;

    while(!q.empty()) {

        BinaryTreeNode* node = q.front();
        q.pop();

        if(node->data == start) {
            res = node;
        }

        if(node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }

        if(node->right) {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }

    return res;
}


// Function 3: Calculate minimum time to burn tree
int timeToBurnTree(BinaryTreeNode* root, int start) {

    if(root == NULL) return 0;

    map<BinaryTreeNode*, BinaryTreeNode*> mpp;

    BinaryTreeNode* target = bfsToMapParents(root, mpp, start);

    if(target == NULL) return -1;

    int maxi = findMaxDistance(mpp, target);

    return maxi;
}


// Main function
int main() {

    // -1 represents NULL
    vector<int> arr = {
        1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8
    };

    BinaryTreeNode* root = constructTree(arr);

    int start = 5;

    cout << "Minimum time to burn tree: "
         << timeToBurnTree(root, start);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

1. constructTree():
   O(N)

2. bfsToMapParents():
   O(N log N)
   Because we use map to store parent pointers.

3. findMaxDistance():
   O(N log N)
   Because every node is visited once and map is
   used for visited checking.

Overall TC = O(N log N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

1. Parent map = O(N)
2. Visited map = O(N)
3. Queue = O(N)

Overall SC = O(N)

N = Total number of nodes in the binary tree.
--------------------------------------------------
*/
