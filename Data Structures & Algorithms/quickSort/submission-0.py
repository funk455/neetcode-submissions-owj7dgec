# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        return self.qucksortdfs(pairs,0,len(pairs)-1)
    def qucksortdfs(self,pairs:List[Pair],s,e):
        if e-s+1<=1:
            return pairs
        p = pairs[e]
        left = s
        #小的插入前面
        for i in range(s,e):
            if pairs[i].key < p.key:
                temp = pairs[left]
                pairs[left] = pairs[i]
                pairs[i] = temp
                left+=1
        pairs[e] = pairs[left]
        pairs[left] = p
        self.qucksortdfs(pairs,s,left-1)
        self.qucksortdfs(pairs,left+1,e)
        return pairs