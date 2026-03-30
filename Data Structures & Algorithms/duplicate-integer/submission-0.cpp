class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::map<int,int> hash;
        for (const auto & num: nums) {
            hash[num]++;
            if (hash[num] > 1) {
                return true;
            }
        }
        return false;
    }
};