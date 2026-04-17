class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        temp = []
        def dfs(i,sumv):
            if sumv > target or i>=len(nums):
                return
            if sumv==target:
                res.append(temp.copy())
                return
            temp.append(nums[i])
            dfs(i,sumv+nums[i])
            temp.pop()
            dfs(i+1,sumv)
        dfs(0,0)
        return res;
            