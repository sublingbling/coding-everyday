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
        int countA=0, countB=0;
        
        ListNode *A = headA, *B=headB;
        while(headA){
            countA++;
            headA=headA->next;
        }
        while(headB){
            countB++;
            headB=headB->next;
        }
        for(int i=0;i<abs(countA-countB);i++){
            if(countA>countB) A=A->next;
            else B=B->next;
        }
        
        while(A){
            if(A==B) return A;
            A=A->next;
            B=B->next;
        }
        return NULL;
    }
};
