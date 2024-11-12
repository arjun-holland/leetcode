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
    ListNode* middleNode(ListNode* head) {
         if (!head) return nullptr;
        if(head->next==nullptr)return head;
        ListNode* f=head;
        ListNode* s=head;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        // When fast reaches the end, slow will be at the middle
        return s;
    }
};