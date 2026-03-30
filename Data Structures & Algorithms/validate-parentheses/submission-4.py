class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        charmap = {'}':'{',']':'[',')':'('}
        for c in s:
            if c in charmap:
                if stack and stack[-1] == charmap[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return True if not stack else False