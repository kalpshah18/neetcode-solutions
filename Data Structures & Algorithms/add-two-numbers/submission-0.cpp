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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(l1 != nullptr || l2 != nullptr || carry){
            int v1 = l1 == nullptr ? 0 : l1->val;
            int v2 = l2 == nullptr ? 0: l2->val;
            int res = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            curr->next = new ListNode(res);
            curr = curr->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return dummy->next;
    }
};
