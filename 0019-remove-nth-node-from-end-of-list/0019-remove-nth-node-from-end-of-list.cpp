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
//a=slw b=fast
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode*a=head,*b=head;
        while(n--){
            b=b->next;
        }
        if(b==NULL)return a->next;
        while(b->next!=NULL){
            a=a->next;
            b=b->next;
     }
        a->next=a->next->next;
        return head;
    }
};