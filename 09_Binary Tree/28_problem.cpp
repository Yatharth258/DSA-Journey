//serailize and deserailize a binary tree
//You need two write two functions thats completely your logic 
//one function convert the tree into a string
//while other function convert that string again into a binary tree


#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


// Encodes a tree to a single string.
string serialize(TreeNode* root) {

    if(root == NULL) return "";

    string s = "";

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* curNode = q.front();
        q.pop();

        if(curNode == NULL) {
            s.append("#,");
        }
        else {
            s.append(to_string(curNode->val) + ',');
        }

        if(curNode != NULL) {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }

    return s;
}


// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {

    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');

    TreeNode* root = new TreeNode(stoi(str));

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* node = q.front();
        q.pop();

        // Build left child
        getline(s, str, ',');

        if(str == "#") {
            node->left = NULL;
        }
        else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        // Build right child
        getline(s, str, ',');

        if(str == "#") {
            node->right = NULL;
        }
        else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}


// Main function
int main() {

    // Manually construct binary tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize tree
    string data = serialize(root);

    cout << "Serialized Tree: " << data << endl;

    // Deserialize string back to tree
    TreeNode* newRoot = deserialize(data);

    return 0;
}


/*
--------------------------------------------------
TIME COMPLEXITY:
--------------------------------------------------

serialize():
    O(N)

    Every node and NULL child is processed once.

deserialize():
    O(N)

    Every node is created and processed once.

Overall TC = O(N)

--------------------------------------------------
SPACE COMPLEXITY:
--------------------------------------------------

serialize():
    O(N) for queue and serialized string.

deserialize():
    O(N) for queue and newly constructed tree.

Overall SC = O(N)

N = Total number of nodes.
--------------------------------------------------
*/
