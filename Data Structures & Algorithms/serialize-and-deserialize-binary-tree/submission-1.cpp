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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        ans+=to_string(root->val) + ',';
        while(!q.empty())
        {
            auto x=q.front();q.pop();
            if(x->left)
            {
                q.push(x->left);
                ans+=to_string(x->left->val) + ',';
            }
            else
            {
                ans+="n,"; 
            } 
            if(x->right)
            {
                q.push(x->right);
                ans+=to_string(x->right->val) + ',';
            }
            else ans+="n,";
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        string val="";
        int i=0;
        while(i<data.size() && data[i]!=',')
        {
            val=val + data[i];
            i++;
        }
        i++;
        TreeNode *root=new TreeNode(stoi(val));
        queue<TreeNode*> q;q.push(root);
        while(!q.empty() && i < data.size())
        {
            TreeNode *temp=q.front();q.pop();
            if(data[i]=='n') {
                temp->left=nullptr;
                i=i+2;
            }
            else
            {
                string val="";
                while(i<data.size() && data[i]!=',')
                {
                    val=val + data[i];
                    i++;
                }
                i++;
                TreeNode *t=new TreeNode(stoi(val));
                temp->left=t;
                q.push(t);
            }
            if(data[i]=='n') { 
                temp->right=nullptr;
                i=i+2;
            }
            else
            {
                string val1="";
                while(i<data.size() && data[i]!=',')
                {
                    val1=val1 + data[i];
                    i++;
                }
                i++;
                TreeNode *t1=new TreeNode(stoi(val1));
                temp->right=t1;
                q.push(t1);
            }
        }
        return root;
    }
};
