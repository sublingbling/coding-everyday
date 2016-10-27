class Solution:
    # @param {string} s A string
    # @return {boolean} whether the string is a valid parentheses
    def isValidParentheses(self, s):
        stack = []
        dict = {')':'(', '}':'{', ']':'['}
        for ch in s:
            if ch in dict.values():
                stack.append(ch)
            elif ch in dict.keys():
                if stack == [] or dict[ch] != stack.pop():
                    return False
            else:
                return False
                
        return stack == []
