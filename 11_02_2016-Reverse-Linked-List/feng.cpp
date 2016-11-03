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
    ListNode* reverseList(ListNode* head) {
        if(NULL==head) return head;
        ListNode* pre=NULL;
        ListNode* cur = head;
        while(cur->next){
            ListNode* post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        cur->next = pre;
        return cur;
    }
};
