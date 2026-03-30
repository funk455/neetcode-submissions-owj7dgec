class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<vector<int>> res;
        vector<int> temp;
        traceback(nums,target,res,temp,0);
        return res;
    }
    void traceback(vector<int>& nums,int target,vector<vector<int>> &res,vector<int> temp,int i) {
        if (target==0) {
            res.push_back(temp);
            return;
        }
        if(target<0 || i >= nums.size()) {
            return;
        }
        temp.push_back(nums[i]);
        traceback(nums,target-nums[i],res,temp,i);
        //下面两步可以改为在for函数进行
        temp.pop_back();
        //跳过这个数
        traceback(nums,target,res,temp,i+1);
    }
};
