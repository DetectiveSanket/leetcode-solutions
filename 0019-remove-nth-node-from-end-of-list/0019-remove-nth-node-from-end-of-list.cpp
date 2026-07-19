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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
  // Approach :- Linked List
  // Time :- O(N)
  // Space :- O(1)  

        ListNode* temp = head;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        if (n > length) {
            return head; // Or handle this as an error
        }

        if (n == length) {
            return head->next; // Remove the head
        }

        int cnt = length - n;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < cnt; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        return head;
    }
};