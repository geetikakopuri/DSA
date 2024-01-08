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
    ListNode* rotateRight(ListNode* head, int k) {
        
    ListNode* tail=head;
    ListNode* temp=head;
     int len=1;
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
     while(tail->next!=NULL)
     {
          len++;
          tail=tail->next;
     }
     if(k%len==0)
     {
          return head;
     }
     k=k%len;
     tail->next=head;
     int end=len-k;
     int cnt=1;
     while(temp!=NULL)
     {
          if(cnt==end)
          {
               head=temp->next;
               temp->next=NULL;
          }
          cnt++;
          temp=temp->next;
     }
     return head;
    }
};