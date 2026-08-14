/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node *root,unordered_map<Node*,Node*> &mpp)
    {
        if(root==nullptr) return nullptr;
        if(mpp.count(root)) return mpp[root];
        Node *temp=new Node(root->val);
        mpp[root]=temp;
        for(auto x:root->neighbors)
        {
            Node *t=clone(x,mpp);
            temp->neighbors.push_back(t);
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mpp;
        return clone(node,mpp);
    }
};
