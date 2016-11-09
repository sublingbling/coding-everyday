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
        ListNode* A=headA;
        ListNode* B=headB;
        while(A && B){
            A=A->next;
            B=B->next;
        }
		
        while(A){
            A=A->next;
            headA=headA->next;
        }
		while(B){
            B=B->next;
            headB=headB->next;
        }
       
        while(headA && headB && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
