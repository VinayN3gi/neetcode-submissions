/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Compare
{
    public:
    bool operator()(ListNode *a,ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return {};
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(int i=0;i<lists.size();i++)
        {
            pq.push(lists[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *prev=dummy;
        while(!pq.empty())
        {
           auto x=pq.top();pq.pop();
           prev->next=x;
           prev=x;
           if(x->next) pq.push(x->next);
        }
        return dummy->next;
    }
};
