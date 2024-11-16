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
    vector<int> v;
    int i = 0;

    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        v.push_back(head->val);
        
        bool result = isPalindrome(head->next);

        if (!result || v[i++] != head->val) {//once we get return false we dont need to check  
            return false;
        }

        return true;
    }
};
