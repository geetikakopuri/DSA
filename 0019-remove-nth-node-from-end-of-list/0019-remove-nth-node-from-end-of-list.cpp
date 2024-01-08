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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=1;i<=n;i++)
        {
            if(fast==NULL)
            {
                return head;
            }
            fast=fast->next;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        while(fast!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==NULL)
        {
            ListNode* delnode=head;
            head=head->next;
            delete(delnode);
        }
        else
        {
            ListNode* delnode=slow;
            prev->next=slow->next;
            delete(delnode);
        }
        return head;
    }
};