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
    void reverse(ListNode*s,ListNode*e){
        ListNode*p=NULL,*t=s,*n=s->next;
        while(p!=e){
            t->next=p;
            p=t;
            t=n;
         if(n!=NULL)n=n->next;
        }  
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
     
        //1 basecase
        if(head==NULL||head->next==NULL||k==1)return head;
        // 2 uske bad head bnaya
        ListNode*s=head,*e=head;
        int c=k-1;
        while(c--){
            e=e->next;
            if(e==NULL)return head;
            
        }
                   ListNode*nextHead= reverseKGroup(e->next,k);

     
        reverse(s,e);
           //ListNode nextHead= reverseKGroup(e->next,k)
            s->next=nextHead;
        return e;
    }
};