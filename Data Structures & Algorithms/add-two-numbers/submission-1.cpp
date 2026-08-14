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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *dummy=new ListNode(-1);
        ListNode *prev=dummy;
        while(l1 || l2)
        {
            if(l1) {
                carry=carry + l1->val;
                l1=l1->next;
            }
            if(l2) {
                carry=carry + l2->val;
                l2=l2->next;
            }
            int sum=carry  % 10;
            carry = carry /10;
            ListNode *temp=new ListNode(sum);
            prev->next=temp;
            prev=temp; 
        }

        if(carry > 0)
        {
            ListNode *temp=new ListNode(carry);
            prev->next=temp;
        }
        return dummy->next;
    }
};
