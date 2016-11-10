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
        if (!headA || !headB) return NULL;
        
        ListNode *ptrA = headA, *ptrB = headB;
        int sizeA = 0, sizeB = 0;
        while (ptrA)
        {
            sizeA++;
            ptrA = ptrA->next;
        }
        while (ptrB)
        {
            sizeB++;
            ptrB = ptrB->next;
        }
        if (sizeA > sizeB)
        {
            ptrA = headA;
            ptrB = headB;
            for (int i=0; i<sizeA-sizeB; i++)
                ptrA = ptrA->next;
        }
        else
        {
            ptrA = headA;
            ptrB = headB;
            for (int i=0; i<sizeB-sizeA; i++)
                ptrB = ptrB->next;
        }
        while (ptrA)
        {
            if (ptrA == ptrB)
                return ptrA;
            else
            {
                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }
        }
        return NULL;
    }
};
