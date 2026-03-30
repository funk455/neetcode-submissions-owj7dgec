class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = 0, k = numbers.size()-1;
        while (j < k)
        {
            /* code */
            auto cur = numbers[j] + numbers[k];
            if ( cur < target) {
                j++;
            }else if ( cur > target) {
                k--;
            }else {
                return {j+1,k+1};
            }
        }
        return {};
    }
};