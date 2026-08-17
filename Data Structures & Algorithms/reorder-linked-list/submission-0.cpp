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

class Solution {
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *prev=nullptr;
        ListNode *temp=head;
        while(temp)
        {
            ListNode *t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *t=slow->next;
        slow->next=nullptr;
        ListNode *t1=rev(t);
        ListNode *t2=head;
        while(t1!=nullptr && t2!=nullptr)
        {
            ListNode* next1 = t1->next;
            ListNode* next2 = t2->next;

            t2->next = t1;
            t1->next = next2;

            t2 = next2;
            t1 = next1;
        }
    }
};
