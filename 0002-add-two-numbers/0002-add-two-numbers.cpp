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
   ListNode* check(ListNode* l1, ListNode* l2, int carry){
    // Base case: if both lists are null and no carry, return null
       if (!l1 && !l2 && carry == 0) {
        return nullptr;
       }
    // Calculate the sum of current digits and carry
       int sum = carry;
       if (l1) {
          sum += l1->val; // Add value from l1 if available
          l1 = l1->next; // Move to the next node in l1
       }
       if (l2) {
          sum += l2->val; // Add value from l2 if available
          l2 = l2->next; // Move to the next node in l2
       }
    // Create a new node for the current digit
       ListNode* resultNode = new ListNode(sum % 10);
    // Recur for the next digits with updated carry
       resultNode->next = check(l1, l2, sum / 10);
    return resultNode; // Return the current node 
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return check(l1,l2,0);
    }
};