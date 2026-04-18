class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        temp = []
        candidates.sort()
        def dfs(index,sum):
            if sum == target:
                res.append(temp.copy())
                return
            if index>=len(candidates) or sum>target:
                return
            temp.append(candidates[index])
            dfs(index+1,sum+candidates[index])
            temp.pop()
            while index+1<len(candidates) and candidates[index] == candidates[index+1]:
                index+=1
            dfs(index+1,sum)
        dfs(0,0)
        return res