# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def merge(l1, l2):
            dummy = cur = ListNode(0)
            while l1 and l2:
                if l1.val < l2.val:
                    cur.next = l1
                    l1 = l1.next
                else:
                    cur.next = l2
                    l2 = l2.next
                cur = cur.next
            cur.next = l1 or l2
            return dummy.next
            
            
        # split the list then sorted merging
        
        # check valid
        if not head or not head.next :
            return head
        # split 
        prev = slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            prev = slow
            slow = slow.next
        prev.next = None
        
        h1, h2 = self.sortList(head), self.sortList(slow)
        # merge
        return merge(h1, h2)
        
