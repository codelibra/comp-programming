/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int sumUp(TreeNode* node, int parentGreater)
    {
      if(node==NULL)
        return 0;

      int rightTree = sumUp(node->right,parentGreater);
      int value = node->val;
      node->val = node->val + rightTree + parentGreater;
      int leftTree = sumUp(node->left,node->val);
      return value + rightTree + leftTree;
    }

    TreeNode* convertBST(TreeNode* root) {
        sumUp(root,0);
        return root;
    }
};
