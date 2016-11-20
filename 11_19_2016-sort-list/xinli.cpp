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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int pivotVal = head->val;
        ListNode *lessListHead = new ListNode(-1);
        ListNode *sameListHead = new ListNode(-1);
        ListNode *moreListHead = new ListNode(-1);
        ListNode *iter = head;
        ListNode *lessListTail = lessListHead;
        ListNode *sameListTail = sameListHead;
        ListNode *moreListTail = moreListHead;
        while(iter) {
            if (iter->val > pivotVal) {
                moreListTail->next = iter;
                moreListTail = moreListTail->next;
            } else if (iter->val == pivotVal) {
                sameListTail->next = iter;
                sameListTail = sameListTail->next;
            } else {
                lessListTail->next = iter;
                lessListTail = lessListTail->next;
            }
            iter = iter->next;
        }
        sameListTail->next = NULL;
        lessListTail->next = NULL;
        moreListTail->next = NULL;
        lessListHead->next = sortList(lessListHead->next);
        moreListHead->next = sortList(moreListHead->next);
        sameListTail->next = moreListHead->next;
        ListNode* result = sameListHead->next;
        
        //Refind the tail after the recursion call.
        lessListTail = lessListHead;
        while (lessListTail->next) { lessListTail = lessListTail->next; }
        if(lessListTail) {
            lessListTail->next = sameListHead->next;
            result = lessListHead->next;
        }
        delete lessListHead;
        delete sameListHead;
        delete moreListHead;
        return result;
    }
};
