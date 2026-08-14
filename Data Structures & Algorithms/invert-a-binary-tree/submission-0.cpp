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
    TreeNode *solve(TreeNode *root)
    {
        if(root==nullptr) return nullptr;
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        root->left=solve(right);
        root->right=solve(left);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
    }
};
