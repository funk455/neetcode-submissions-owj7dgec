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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return {};
        dfs(root,res,0);
        return res;
    }
    void dfs(TreeNode * root,vector<int> & res,int depth) {
        if (root==nullptr) 
            return;
        if (res.size() == depth) {
            res.push_back(root->val);
        }
        dfs(root->right,res,depth+1);
        dfs(root->left,res,depth+1);
    }
};
