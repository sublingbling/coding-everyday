/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode removeNthFromEnd(ListNode head, int n) {
        // write your code here
        if (n <= 0 || head == null) {
            return null;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode predelete = dummy;
        //head = dummy;
        
        //move the first pointer to n
        for (int i = 0; i < n; i++) {
            head = head.next;
        }
        
        //move both pointers togerther
        while (head != null) {
            head = head.next;
            predelete = predelete.next;
        }
        
        predelete.next = predelete.next.next;
        
        return dummy.next;
        
        
    }
}
