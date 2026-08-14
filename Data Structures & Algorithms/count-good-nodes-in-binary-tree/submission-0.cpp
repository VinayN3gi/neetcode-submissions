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
    void solve(TreeNode* root,int maxEle,int &count)
    {
        if(root==nullptr) return ;
        if(root->val >= maxEle)
        {
            maxEle=root->val;
            count++;
        }
        solve(root->left,maxEle,count);
        solve(root->right,maxEle,count);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxEle=INT_MIN;
        solve(root,maxEle,count);
        return count;
    }
};
