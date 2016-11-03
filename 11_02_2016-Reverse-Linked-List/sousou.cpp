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
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode *ptr=head, *next=head->next, *prev=NULL;
        
        while(next)
        {
            ptr->next = prev;
            prev = ptr;
            ptr = next;
            next = next->next;
        }
        ptr->next = prev;
        return ptr;
    }
};
