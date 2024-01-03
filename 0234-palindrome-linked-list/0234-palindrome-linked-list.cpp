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

ListNode* reverse(ListNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL)
    {
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return true;
        }
        ListNode* temp=head;
        ListNode*slow=temp;
        ListNode*fast=temp;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverse(slow->next);
        ListNode* second=newHead;
        slow=head;
        while(second!=NULL)
        {
            if(slow->val!=second->val)
            {
                reverse(newHead);
                return false;
            }
            slow=slow->next;
            second=second->next;
        }
        reverse(newHead);
        return true;
        
    }
};