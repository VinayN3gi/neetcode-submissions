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
        if(lists.size()==0) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *prev=nullptr;
        prev=dummy;
        while(!pq.empty())
        {
            ListNode *temp=pq.top();pq.pop();
            if(temp->next!=nullptr) pq.push(temp->next);
            ListNode *newNode=new ListNode(temp->val);
            prev->next=newNode;
            prev=newNode;
        }
        return dummy->next;
    }
};
