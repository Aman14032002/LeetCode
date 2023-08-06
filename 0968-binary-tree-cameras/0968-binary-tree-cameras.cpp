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
    int minCameraCover(TreeNode *root) {
  if (!root) {
    return 0;
  }

  int cameras = 0;

  function<int(TreeNode *, int)> dfs = [&](TreeNode *node, int state) -> int {
    if (!node) {
      return state;
    }

    int left = dfs(node->left, 2);
    int right = dfs(node->right, 2);

    if (left == 0 || right == 0) {
      cameras++;
      return 1;
    } else if (left == 1 || right == 1) {
      return 2;
    } else {
      return 0;
    }
  };

  int state = dfs(root, 0);
  if (state == 0) {
    cameras++;
  }

  return cameras;
}
};
                    

















































// int minCameraCoverSub(TreeNoderoot, int status) {
// if (!root) {
// *status = 0;
// return 0;
// }
// int leftStatus = -1, rightStatus = -1;
// int count = minCameraCoverSub(root->left, &leftStatus) + minCameraCoverSub(root->right, &rightStatus);
// if (leftStatus == -1 || rightStatus == -1) { // child must be covered.
// *status = 1;
// return count + 1;
// }
// status = (leftStatus == 1 || rightStatus == 1) ? 0 : -1;
// return count;
// }
// int minCameraCover(TreeNode root) {
// int status = -1; // uncovered. 0 covered but not in the root; 1 covered in the root.
// int count = minCameraCoverSub(root, &status);
// return (status == -1) + count;
// }
// };