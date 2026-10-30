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
    int ans=INT_MIN;
    int solve(TreeNode *root)
    {
        if(root==nullptr) return 0;
        int x=solve(root->left);
        int y=solve(root->right);
        int max_x=max(x,0);
        int max_y=max(y,0);
        ans=max(ans,max_x + max_y + root->val);
        return max(max_x,max_y) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
