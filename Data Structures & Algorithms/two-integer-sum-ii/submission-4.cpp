class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
                int j = 0, k = numbers.size();
        for (int i = 0; i < numbers.size()-1; i++) {
            j = i+1; 
            k = numbers.size();
            while (j < k) {
                int mid = j + (k-j)/2;
                if ( numbers[i] + numbers[mid] < target) {
                    j = mid+1;
                }else if ( numbers[i] + numbers[mid] > target) {
                    k = mid;
                }else {
                    return {i+1, mid+1};
                }
        }
        }
        return {};
    }
};
