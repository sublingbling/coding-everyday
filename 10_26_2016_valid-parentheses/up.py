class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # build parentheses dictionary
        D = {')':'(', '}':'{', ']':'['}
        
        stack = []
        left, right= '({[', ')}]'
        # loop
        for c in s:
            # it's a parentheses
            if c in left:
                stack.append(c)
            elif c in right :
                # it's a right one
                if not stack:
                    # nothing in stack, not valid 
                    return False
                else :
                    # stack has something, check it
                    if stack[-1] == D[c]:
                        # stack has left 
                        stack.pop()
                    else:
                        # stack doesn't have a left
                        return False
                            
        
        # check open left
        if stack:
            return False
        else:
            return True
