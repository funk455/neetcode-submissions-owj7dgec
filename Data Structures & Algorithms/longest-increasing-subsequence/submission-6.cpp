class Solution {
public:
        map<pair<int,int>, int> memo;
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums,0,INT_MIN);
    }
    int dfs(vector<int>& nums,int i,int prev){
        if (i == nums.size())
            return 0;
        if (memo.count({i, prev})) return memo[{i, prev}];
        int res = dfs(nums, i + 1, prev);  // 跳过 nums[i]
    if (nums[i] > prev)
        res = max(res, 1 + dfs(nums, i + 1, nums[i]));  // 选 nums[i]

    return memo[{i, prev}] = res;
    }
};
