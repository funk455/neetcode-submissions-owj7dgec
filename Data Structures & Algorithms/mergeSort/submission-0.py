# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        return self.mergesorthelper(pairs,0,len(pairs)-1)
    def mergesorthelper(self,pairs:list[Pair],s,e):
        if e-s+1<=1:
            return pairs
        m = (e+s)//2
        self.mergesorthelper(pairs,s,m)
        self.mergesorthelper(pairs,m+1,e)
        self.merge(pairs,s,m,e)
        return pairs
    def merge(self,arr:List[Pair],s,m,e):
        arrl = arr[s:m+1]
        arrr = arr[m+1:e+1]
        i = 0
        j = 0
        k = s
        while i<len(arrl) and j < len(arrr):
            if arrl[i].key <= arrr[j].key:
                arr[k] = arrl[i]
                i+=1
            else:
                arr[k] = arrr[j]
                j+=1
            k+=1
        while i < len(arrl):
            arr[k] = arrl[i]
            k+=1
            i+=1
        while j < len(arrr):
            arr[k] = arrr[j]
            k+=1
            j+=1