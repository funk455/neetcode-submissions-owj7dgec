class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> mem;
        return dfs(0,0,nums,target,mem);
    }
    int dfs(int i, long long current,vector<int>& nums, int target,unordered_map<string,int>& mem){
        if (i == nums.size()) {
            return current == target?1:0;
        }
        string key = to_string(i) + '_' + to_string(current);
        if (mem.count(key)) return mem[key];
        // 选择 1：加上 nums[i]
        int ways1 = dfs(i + 1, current + nums[i], nums, target, mem);
        
        // 选择 2：减去 nums[i]
        int ways2 = dfs(i + 1, current - nums[i], nums, target, mem);
        
        // 记录结果
        mem[key] = ways1 + ways2;
        return mem[key];
    }
};
