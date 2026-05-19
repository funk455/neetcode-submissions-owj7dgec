class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curmin = 1,curmax = 1;
        for (int num : nums) {
            int temp = curmax * num;
            curmax = max(max(num*curmax,num*curmin),num);
            curmin = min(min(temp,num * curmin),num);
            res = max(res,curmax);
        }
        return res;
    }
};
