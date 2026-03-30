class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)) :
            j,k = i+1,len(numbers)-1
            tmp = target - numbers[i]
            while j <= k:
                mid = j + (k-j)//2
                if numbers[mid] == tmp:
                    return [i+1,mid+1]
                elif numbers[mid] < tmp:
                    j = mid+1
                else :
                    k = mid-1
        return []