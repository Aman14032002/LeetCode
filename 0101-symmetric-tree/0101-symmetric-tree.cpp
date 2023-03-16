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
    bool Helper(TreeNode *lnode , TreeNode *rnode)
    {
        if((lnode== NULL && rnode!= NULL ) || (lnode != NULL && rnode == NULL)) return false;
        if(lnode==NULL && rnode == NULL) return true;
        if(lnode->val != rnode->val) return false;
        
        return Helper(lnode->left, rnode->right) && Helper(lnode->right , rnode->left);
        
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        return Helper(root->left , root->right);
        
    }
};