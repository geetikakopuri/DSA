/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* collisionpoint(ListNode* s,ListNode* f,int d)
    {
    while(d)
    {
        d--;
        f=f->next;
    }
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    return s;   
    }

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* t1=headA;
    ListNode* t2=headB;
    int n1=0,n2=0;
    while(t1!=NULL||t2!=NULL)
    {
        if(t1)
        {
            t1=t1->next;
            n1++;
        }
        if(t2)
        {
            t2=t2->next;
            n2++;
        }
    }
    if(n2>n1)
    {
        return collisionpoint(headA,headB,n2-n1);
    }
    else
    {
        return collisionpoint(headB,headA,n1-n2);
    }
        
        // if(headA!=NULL||headB!=NULL)
        // {
        //     return NULL;
        // }
        // ListNode* t1=headA;
        // ListNode* t2=headB;
        // while(t1!=t2)
        // {
        //     t1=t1->next;
        //     t2=t2->next;
        //     if(t1==t2)
        //     {
        //         return t1;
        //     }
        //     if(t2==NULL)
        //     {
        //         t2=headA;
        //     }
        //     if(t1==NULL)
        //     {
        //         t1=headB;
        //     }
        // }
        // return t1;
    }
};