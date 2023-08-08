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
    // calculate the height of each node
    // if diff between height of leftsubtree and rightsubtree is greater than 1, it's not balanced
    int dfs(TreeNode* root){
        if(!root)  // nullptr
            return 0;
        int left=dfs(root->left),right=dfs(root->right); 
        if(left==-1 || right==-1 || abs(left-right)>=2) 
            return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
};