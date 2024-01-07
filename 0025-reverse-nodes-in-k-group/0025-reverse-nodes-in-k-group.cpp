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
ListNode* rev(ListNode* temp)
{
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

ListNode* findkthnode(ListNode*temp,int k)
{
    k--;
    while(temp!=NULL&&k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        ListNode* nextnode=NULL;
        while(temp!=NULL)
        {
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode==NULL)
            {
                if(prevlast)
                {
                    prevlast->next=temp;
                }
                break;
            }
            nextnode=kthnode->next;
            kthnode->next=NULL;
            rev(temp);
            if(temp==head)
            {
                head=kthnode;
            }
            else
            {
                prevlast->next=kthnode;
            }
            prevlast=temp;
            temp=nextnode;
        }
        return head;
    }
};