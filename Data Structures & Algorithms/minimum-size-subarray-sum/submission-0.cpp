class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 9999;
        int left = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum+=nums[r];
            while(sum>=target) {
                res = min(res,r-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return res==9999?0:res;
    }
};