/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* _mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode(-1);
        ListNode* iter = head;
        while (a && b) {
            if (a->val < b->val) {
                iter->next = a;
                a = a->next;
            } else {
                iter->next = b;
                b = b->next;
            }
            iter = iter->next;
        }
        if (!a) {
            iter->next = b;
        } else {
            iter->next = a;
        }
        iter = head->next;
        delete head;
        return iter;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* halfHead = slow->next;
        slow->next = NULL;
        head = sortList(head);
        halfHead = sortList(halfHead);
        head = _mergeTwoLists(head, halfHead);
        return head;
    }
};
