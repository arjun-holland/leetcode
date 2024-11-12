/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if (head == nullptr) return false; // Check if the list is empty

    ListNode* slow = head;  // Slow pointer
    ListNode* fast = head;  // Fast pointer

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          // Move slow by 1
        fast = fast->next->next;   // Move fast by 2

        if (slow == fast) {         // Cycle detected
            return true;
        }
    }

    return false; // No cycle found
    }
};