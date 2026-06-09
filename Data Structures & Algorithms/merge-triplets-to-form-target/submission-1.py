class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        res = set()
        for l in triplets:
            if l[0] > target[0] or l[1] > target[1] or l[2] > target[2]:
                continue
            for i , v in enumerate(l):
                if v == target[i]:
                    res.add(i)
        return len(res) == 3