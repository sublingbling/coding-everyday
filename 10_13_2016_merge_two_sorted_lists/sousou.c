/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    struct ListNode *head = NULL;
    if (l1->val > l2->val)
    {
        head = l2;
        l2 = l2->next;
    }
    else
    {
        head = l1;
        l1 = l1->next;
    }
    
    struct ListNode *ptr = head;

    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            ptr->next = l2;
            ptr = ptr->next;
            l2 = l2->next;
        }
        else
        {
            ptr->next = l1;
            ptr = ptr->next;
            l1 = l1->next;
        }
    }
    
    if (!l1) ptr->next = l2;
    if (!l2) ptr->next = l1;
    
    return head;
}
