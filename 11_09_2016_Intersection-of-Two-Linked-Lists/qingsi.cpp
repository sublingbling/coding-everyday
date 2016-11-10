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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        ListNode* p = headA;
        while (p) {
            lengthA++;
            p = p->next;
        }
        p = headB;
        while (p) {
            lengthB++;
            p = p->next;
        }
        p = headA;
        ListNode* q = headB;
        if (lengthA > lengthB) {
            std::swap(p, q);
            std::swap(lengthA, lengthB);
        }
        while (p && q) {
            while (lengthA < lengthB) {
                q = q->next;
                lengthB--;
            }
            if (p == q) {
                return p;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        return NULL;
    }
};
