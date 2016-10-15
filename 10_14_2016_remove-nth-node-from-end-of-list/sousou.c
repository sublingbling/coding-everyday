/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (!head) return head;

    struct ListNode root;
    root.next = head;
    struct ListNode *endNode = &root;
    struct ListNode *revNode = &root;
    
    for(int i=0; i<n; i++)
    {
        endNode = endNode->next;
    }

    while(endNode->next)
    {
        endNode = endNode->next;
        revNode = revNode->next;
    }
    
    revNode->next = revNode->next->next;

    return root.next;
}
