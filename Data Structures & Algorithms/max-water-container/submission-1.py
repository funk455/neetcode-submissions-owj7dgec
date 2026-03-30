class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l,r,res = 0,len(heights)-1,0
        while l < r:
            cur = min(heights[l],heights[r]) * (r-l)
            res = max(res,cur)
            if heights[l] < heights[r]:
                l+=1;
            else:
                r-=1;
        return res