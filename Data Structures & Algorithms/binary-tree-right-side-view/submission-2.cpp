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
        if(root==nullptr) return {};
        unordered_map<int,int> mpp;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *x=q.front();q.pop();
                mpp[count]=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            count++;
        }
        vector<int> ans(count,0);
        for(auto &[val,freq]:mpp)
        {
            ans[val]=freq;
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};
