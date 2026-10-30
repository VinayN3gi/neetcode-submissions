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
    Node *solve(Node *node,unordered_map<Node*,Node*> &mpp)
    {
        if(mpp.count(node)) return mpp[node];
        if(node==nullptr) return nullptr;
        Node *temp=new Node(node->val);
        mpp[node]=temp;
        for(auto &t : node->neighbors)
        {
            temp->neighbors.push_back(solve(t,mpp));
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mpp;
        return solve(node,mpp);
    }
};
