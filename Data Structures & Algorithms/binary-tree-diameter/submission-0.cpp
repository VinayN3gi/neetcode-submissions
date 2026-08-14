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
    int solve(TreeNode *root,int &ans)
    {
        if(root==nullptr) return 0;
        int x=solve(root->left,ans);
        int y=solve(root->right,ans);
        ans=max(ans,x+y);
        return 1 + max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
