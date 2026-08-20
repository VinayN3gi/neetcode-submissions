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
    TreeNode* build(vector<int> &preorder,
    vector<int> inorder,unordered_map<int,int> &mpp,
    int preS,int preE,int inS,int inE)
    {
        if(preS > preE || inS > inE) return nullptr;
        int val=preorder[preS];
        TreeNode *root=new TreeNode(val);
        int pos=mpp[val];
        int leftSize=pos - inS;
        root->left=build(preorder,inorder,mpp,preS + 1,preS + leftSize,inS,pos-1);
        root->right=build(preorder,inorder,mpp,preS + leftSize + 1,preE,pos+1,inE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(preorder,inorder,mpp,0,preorder.size()-1,0,inorder.size()-1);
    }
};
