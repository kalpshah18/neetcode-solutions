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
        deque<ListNode*> dq;
        ListNode* temp = head;
        while(temp){
            dq.push_back(temp);
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int idx = 0;
        while(!dq.empty()){
            if(idx & 1){
                curr->next = dq.back();
                curr = curr->next;
                dq.pop_back();
            } else {
                curr->next = dq.front();
                curr = curr->next;
                dq.pop_front();
            }
            idx++;
        }
        curr->next = nullptr;
    }
};
