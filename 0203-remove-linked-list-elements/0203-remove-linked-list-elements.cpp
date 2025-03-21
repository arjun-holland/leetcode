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
    ListNode* solve(ListNode* head, int val){
        if(!head)return nullptr;
        
        head->next = solve(head->next,val);
        
        if(head->val==val){
            ListNode* temp = head;
            head=head->next;
            delete temp;
        }
        return head;
       
    }
    ListNode* removeElements(ListNode* head, int val) {
        return solve(head,val);
    }
};