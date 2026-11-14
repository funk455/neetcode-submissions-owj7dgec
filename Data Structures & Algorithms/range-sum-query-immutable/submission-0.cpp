class NumArray {
public:
    vector<long long> presum; 
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (auto & n : nums) {
            sum+=n;
            presum.push_back(sum);
        }
    }
    int sumRange(int left, int right) {
        int leftsum = left>0?presum[left-1]:0;
        int rightsum = presum[right];
        return rightsum-leftsum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */