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

    void insert(ListNode* to, ListNode* from){
        while(to){
            if(to->next == NULL||to->next->val>from->val){
                from->next = to->next;
                to->next = from;
                return;
            }
            to = to->next;
        }
    }
    
public:
    ListNode* insertionSortList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy_head = new ListNode(0);
        while(head){
            ListNode* t = head->next;
            insert(dummy_head, head);
            head = t;
        }
        return dummy_head->next;
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
private:
    ListNode* tail;
    void insert(ListNode* to, ListNode* from){
        while(to){
            if(to->next == NULL) tail = from;
            if(to->next == NULL||to->next->val>from->val){
                from->next = to->next;
                to->next = from;
                return;
            }
            
            to = to->next;
        }
    }
   
    
public:
    ListNode* insertionSortList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy_head = new ListNode(0);
        tail=NULL;
        while(head){
            ListNode* t = head->next;
            if(tail && head->val>tail->val){ 
                tail->next = head;
                tail = tail->next;
                head->next = NULL;
            }
            else insert(dummy_head, head);
            head = t;
        }
        return dummy_head->next;
    }
};
