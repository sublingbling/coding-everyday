# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        # not sure if n==0 is valid, check here
        if n == 0: 
            return head
        
        ## create root and 2 pointers("prev" and "end"), and set the distance between "prev" and "end" to n+1(dis btn "head"&"end" is n)
        prev = root = ListNode(0)
        root.next = end = head 
        for _ in xrange(n):
            end = end.next
        
        # when "end" run to the end of the list, delete the node prev.next
        while end:
            end = end.next
            prev = prev.next
        prev.next = prev.next.next
        
        return root.next

    
    
##### WAIT, why I need "end"? The "head" is not even used... 
##### 2.0 - remove "end" and let "head" do it. And no need to check n==0 case...

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        ## create root and prev. Prev will point to the target node when head reach the end
        prev = root = ListNode(0)
        root.next = head 
        for _ in xrange(n):
            head = head.next
        
        # delete the node prev.next
        while head:
            head = head.next
            prev = prev.next
        prev.next = prev.next.next
        
        return root.next

### Actually I don't need a dummy head to remove the first node, I can just return head.next....
### so change the code a little bit....

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """

        # move "end" anyway 
        end = head 
        for _ in xrange(n):
            end = end.next
        
        # if "end" reaches the end, remove the first node
        if not end:
            return head.next
        
        # well, it's not the end, I need a root now...
        root = head
        # and hack "end" a bit, to make "head" as a "prev"
        end = end.next
    
        # here we go, to the end... 
        while end:
            head = head.next
            end =  end.next
        head.next = head.next.next
        
        return root
