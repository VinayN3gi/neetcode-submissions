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
        int maxX=max(0,x);
        int maxY=max(0,y);
        int val=root->val + maxX + maxY;
        ans=max(ans,val);
        return root->val + max(maxX,maxY);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
