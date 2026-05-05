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
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        int sz = v.size();
        if(sz == n){
            return v[1];
        } else {
            ListNode* node = v[sz - n - 1];
            node->next = node->next->next;
            return v[0];
        }
    }
};
