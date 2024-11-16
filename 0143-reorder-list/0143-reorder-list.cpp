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
    void reorderList(ListNode* head) {
          // Step 1: Store values in a vector
        vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }

        // Step 2: Reorder the values according to the required pattern
        int n = values.size();
        vector<int> reorderedValues;
        
        for (int i = 0; i < (n + 1) / 2; ++i) {
            reorderedValues.push_back(values[i]); // Add L0, L1, ...
            if (i != n - i - 1) { // Avoid adding Ln again if it's the same
                reorderedValues.push_back(values[n - i - 1]); // Add Ln, Ln-1, ...
            }
        }

        // Step 3: Update linked list with reordered values
        current = head; // Reset current to head of the list
        for (int val : reorderedValues) {
            current->val = val; // Update node's value
            current = current->next; // Move to next node
        }
    }
};