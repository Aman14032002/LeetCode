/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
     if (!root) {
        return "#,";
    }

    string serialized = to_string(root->val) + ",";
    serialized += serialize(root->left);
    serialized += serialize(root->right);

    return serialized;
}

// Helper function for Deserialization Algorithm
TreeNode* buildTree(queue<string>& nodes) {
    string value = nodes.front();
    nodes.pop();

    if (value == "#") {
        return NULL;
    }

    TreeNode* node = new TreeNode(stoi(value));
    node->left = buildTree(nodes);
    node->right = buildTree(nodes);
    return node;
}

// Deserialization Algorithm
TreeNode* deserialize(string data) {
    stringstream ss(data);
    string nodeValue;
    queue<string> nodes;

    while (getline(ss, nodeValue, ',')) {
        nodes.push(nodeValue);
    }

    return buildTree(nodes);
}

// Helper function for tree traversal to verify the correctness of deserialized tree
void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));