class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for ( int i = 0; i < nums.size(); i++) {
            int ans = target-nums[i];
            if ( hash.count(ans) && hash[ans]!=i)
            return {i,hash[ans]};
        }
        return {};
    }
};
