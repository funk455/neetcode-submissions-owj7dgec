class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<long long,int> mem;
        return dfs(0,0,nums,target,mem);
    }
    int dfs(int i, long long current,vector<int>& nums, int target,unordered_map<long long,int>& mem){
        if (i == nums.size()) {
            return current == target?1:0;
        }
        long long key = (long long)i * 100000LL + (current + 50000);
        // 这假设 current 不会超过 ±50000（根据约束条件应该没问题）
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
