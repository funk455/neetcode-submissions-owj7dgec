class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(),nums.end());
        int longgest = 0;
        for ( int num : numset) {
            if ( numset.find(num-1) == numset.end()) {
                int len = 1;
                while( numset.find(num+len)!=numset.end()) {
                    len++;
                }
                longgest = max(longgest,len);
            }
        }
        return longgest;
    }
};
