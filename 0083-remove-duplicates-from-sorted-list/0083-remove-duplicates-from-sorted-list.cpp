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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = NULL, *list = NULL, *a = NULL;
        int l, k;
        list = head;
        a = list;
        while (head != NULL)
        {
            if (head->next != NULL)
            {
                l = head->val;
                p = head->next;
                k = p->val;
                if (l != k)
                {
                    list->val = l;
                    list->next = p;
                    list = list->next;
                }
            }
            else
            {
                list->val = head->val;
                list->next = head->next;
            }
            head = head->next;
        }

        return a;
        
    }
};