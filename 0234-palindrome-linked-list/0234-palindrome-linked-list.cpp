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
    ListNode*reverseList(ListNode*head)
    {
    if(head==NULL)return NULL;;
        ListNode*p=NULL,*c=head,*n=head->next;
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)n=n->next;
            
        }
        return p;
    }
    void print(ListNode*head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
            
        } 
        cout<<endl;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*s=head,*f=head;
        while(f->next!=NULL&&f->next->next!=NULL){
              s=s->next;
            f=f->next->next;
            
        }
     s->next=  reverseList (s->next);
        ListNode*start=head,*mid=s->next;
        while(mid!=NULL){
         if(mid->val!=start->val)return false;
            start=start->next;
            mid=mid->next;
        }
        print (head);
        return true;
    }
};