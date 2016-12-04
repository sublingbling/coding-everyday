"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of linked list.
    @return: The head of linked list.
    """ 
    def insertionSortList(self, head):
        dummy = ListNode(0)
        
        #dummy.next = head
        cur = head #current node to be inserted
        pre = dummy #insert between pre and pre.next
        next = None #next node to be inserted
        
        while cur is not None:
            pre = dummy
            next = cur.next
            #find the node to insert after it
            while pre.next is not None and pre.next.val < cur.val:
                pre = pre.next
            
            cur.next = pre.next
            pre.next = cur

            cur = next
            
        return dummy.next
            
            
        
        
        
