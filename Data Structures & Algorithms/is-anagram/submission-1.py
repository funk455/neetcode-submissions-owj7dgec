class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        chash,thash = {}, {}
        for i in range(len(s)):
            chash[s[i]] = 1 + chash.get(s[i],0)
            thash[t[i]] = 1 + thash.get(t[i],0)
        return chash == thash
        