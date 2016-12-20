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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy_head=new ListNode(0);
        dummy_head->next = head;
        ListNode* node = dummy_head;
        ListNode *pre_node_m, *pre_node_n, *pre_node, *post_node;
        int count = 0;
        while(count <= n){
            if(count == m){
                pre_node_m = pre_node;
                pre_node_n = node;
                pre_node = node;
                node = node->next;
            }
            else if(count > m){
                post_node = node->next;
                node->next = pre_node;
                pre_node = node;
                node = post_node;
            }
            else{
                pre_node = node;
                node = node->next;
            }
            count++;
        }
        pre_node_m->next = pre_node;
        pre_node_n->next = node;
        return dummy_head->next;
    }
};
