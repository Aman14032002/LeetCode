/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      vector<int> ans;
    void s(TreeNode* node)
    {
        if(!node)
            return;
        s(node->left);
        ans.push_back(node->val);
        s(node->right);        
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        s(root);
        return ans;
    }
};