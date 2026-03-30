class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        l,r = 0,len(height)-1
        leftmax,rmax = height[l],height[r]
        res=0
        while l < r :
            if leftmax < rmax:
                l+=1
                leftmax = max(leftmax,height[l])
                res += leftmax - height[l]
            else:
                r-=1
                rmax = max(rmax,height[r])
                res+=rmax - height[r]
        return res