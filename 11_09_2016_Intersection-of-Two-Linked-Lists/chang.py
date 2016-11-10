class Solution:
    # @param headA: the first list
    # @param headB: the second list
    # @return: a ListNode
    def getIntersectionNode(self, headA, headB):
        nodeA = headA
        nodeB = headB
        
        while nodeA != nodeB:
            if nodeA is None:
                nodeA = headB
            else: 
                nodeA = nodeA.next
                
            if nodeB is None:
                nodeB = headA
            else: 
                nodeB = nodeB.next
        
        return nodeA
