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
class cmp{
    public:
    bool operator()(ListNode*a,ListNode*b){
    if((a->val)>=(b->val))  return true;
        
    else return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
    priority_queue<ListNode*,vector<ListNode*>,cmp>q;
    ListNode* dummy= new ListNode();
        ListNode*tail =dummy;
        
        for(int i=0; i < lists.size();i++)
        {
            
        if (lists[i]!=NULL){
            
                q.push(lists[i]);
            }
        }
          while(q.size()){
              ListNode* temp=q.top();
              cout<<temp->val;
              tail->next=temp;
              tail=tail->next;
              q.pop();
             if(temp->next!=NULL)q.push(temp->next);
          
          }
        
           return dummy->next;
        } 
};