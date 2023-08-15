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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(0);  // Dummy node for the small list
    ListNode* largeHead = new ListNode(0);  // Dummy node for the large list
    ListNode* smallTail = smallHead;
    ListNode* largeTail = largeHead;

    while (head) {
        if (head->val < x) {
            smallTail->next = head;
            smallTail = smallTail->next;
        } else {
            largeTail->next = head;
            largeTail = largeTail->next;
        }
        head = head->next;
    }

    // Connect the small list's tail to the large list's head
    smallTail->next = largeHead->next;
    // Disconnect the large list's tail
    largeTail->next = nullptr;

    ListNode* result = smallHead->next;
    delete smallHead;  // Free the memory of the dummy node
    delete largeHead;  // Free the memory of the dummy node

    return result;  // Return the partitioned linked list
}
    
};