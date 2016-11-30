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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        
        ListNode *root;
        root->next = head;
        ListNode *ptr=root, *curr=head;
        while (curr->next)
        {
            if (curr->next->val >= curr->val)
                curr = curr->next;
            else
            {
                while (ptr->next)
                {
                    if (ptr->next->val > curr->next->val)
                    {
                        ListNode *tmp = ptr->next;
                        ptr->next = curr->next;
                        curr->next = curr->next->next;
                        ptr->next->next = tmp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->next;
                    }
                }
                ptr = root;
            }
        }
        return root->next;;
    }
};
