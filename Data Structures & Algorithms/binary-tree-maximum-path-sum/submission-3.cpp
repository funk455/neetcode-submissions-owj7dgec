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
    int res = 0;
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if (root==nullptr) return 0;
        int leftv = dfs(root->left);
        int rightv = dfs(root->right);
        int leftmax = max(leftv,0);
        int rightmax = max(rightv,0);
        int temp = leftmax + rightmax;
        res = max(res,root->val + temp);
        return root->val + max(leftmax,rightmax);
    }
};
