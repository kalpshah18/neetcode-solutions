class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (true) {
            int minIndex = -1;
            int minVal = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (lists[i] && lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    minIndex = i;
                }
            }

            if (minIndex == -1)
                break;

            curr->next = lists[minIndex];
            curr = curr->next;

            lists[minIndex] = lists[minIndex]->next;
        }

        return dummy->next;
    }
};