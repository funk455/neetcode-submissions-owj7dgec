class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numset = set(nums)
        longest = 0;
        for num in  numset:
            if (num-1) not in numset:
                lenth = 1
                while (num+lenth) in numset:
                    lenth+=1
                longest = max(lenth,longest)
        return longest