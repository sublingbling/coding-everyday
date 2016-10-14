
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val){ListNode* t=l1; l1=l2;l2=t;}
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;  
    }
};

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

    void sort(ListNode*& l1, ListNode*& l2){
        if(l1->val > l2->val){ListNode* t= l1; l1=l2; l2=t;}
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        sort(l1,l2);
        ListNode* head=l1;
        ListNode* tail=l1;
        l1 = l1->next;
        
        while(l1 && l2){
            sort(l1,l2);
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        tail->next = l2;
        return head;  
    }
};
