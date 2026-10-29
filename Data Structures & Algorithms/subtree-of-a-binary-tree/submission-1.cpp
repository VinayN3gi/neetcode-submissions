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
    bool same(TreeNode *p,TreeNode *q)
    {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr || q->val!=p->val) return false;
        return same(p->left,q->left) && same(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr) return true;
        if(root==nullptr) return false;

        if(same(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) ||  isSubtree(root->right,subRoot); 
    }
};
