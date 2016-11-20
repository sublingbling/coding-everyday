/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* mergeList(ListNode* a, ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* head = new ListNode(0);
        ListNode* merge = head;
        while(a && b ){
            if(a->val < b->val){
                merge->next = a;
                a = a->next;
            }
            else{
                merge->next = b;
                b = b->next;
            } 
            merge = merge->next;
        }
        merge->next = a?a:b;
        return head->next;
    }
    
    void splitList(ListNode* head, ListNode*& a, ListNode*& b){
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        a = head;
        b = slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode *lo, *hi;
        splitList(head, lo, hi);
        lo = sortList(lo);
        hi = sortList(hi);
        return mergeList(lo,hi);
    }
};
