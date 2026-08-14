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
    void solve(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode *&ans)
    {
        if(root==nullptr) return ;
        if(root->val >= p->val && root->val <= q->val)
        {
            ans=root;
            return;
        }
        else if(root->val > p->val && root->val > q->val) solve(root->left,p,q,ans);
        else solve(root->right,p,q,ans);
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) swap(p,q);
        TreeNode *ans=nullptr;
        solve(root,p,q,ans);
        return ans;
    }
};
