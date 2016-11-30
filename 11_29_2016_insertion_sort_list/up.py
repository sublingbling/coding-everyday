# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        dummy = ListNode(-sys.maxint - 1)
        dummy.next = head
        # add a tail
        node = head
        while node and node.next:
            node = node.next
        node.next = ListNode(0)
        
        pre, cur, nxt = dummy, head, head.next
        while cur and nxt:
            if cur.val < pre.val:
                # not in order , need to insert this cur
                # first save status and del cur
                pre.next = nxt
                cur.next = None
                
                # search the insertion point 
                insPre, insCur = dummy, dummy.next
                while cur.val > insCur.val :
                    insPre, insCur = insPre.next, insCur.next
                insPre.next, cur.next = cur, insCur
                
                # update pre, cur and nxt
                cur, nxt = pre.next, pre.next.next
                
            else:
                # in order 
                pre, cur, nxt = pre.next, cur.next, nxt.next
        
        pre.next = None
        return dummy.next
