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
        ListNode* newHead = head;
        while(head && head->next){
            ListNode* current = head->next;
            head->next=current->next;
            current->next=newHead;
            newHead=current;
        }
        return newHead;
    }
};
