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
    int idx=0;
    unordered_map<int,int> indices;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indices[inorder[i]] = i;
        }
        return dfs(preorder,0,inorder.size()-1);
    }
    TreeNode * dfs(vector<int>& preorder,int l, int r) {
        if ( l > r) return nullptr;
        int val = preorder[idx++];
        TreeNode * root = new TreeNode(val);
        int k = indices[val];
        root->left = dfs(preorder,l,k-1);
        root->right = dfs(preorder,k+1,r);
        return root;
    }
};
