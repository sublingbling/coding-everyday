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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto it = head->next;
        head->next = NULL;
        while (it) {
            auto prev = dummy;
            auto cur = prev->next;
            auto nextIt = it->next;
            int cnt = 0;
            while (cur) {
                if (it->val < cur->val) {
                    prev->next = it;
                    it->next = cur;
                    break;
                }
                prev = cur;
                cur = cur->next;
            }
            if (!cur) {
                prev->next = it;
                it->next = NULL;
            }
            it = nextIt;
        }
        
        head = dummy->next;
        it = dummy;
        delete dummy;
        return head;
    }
};
