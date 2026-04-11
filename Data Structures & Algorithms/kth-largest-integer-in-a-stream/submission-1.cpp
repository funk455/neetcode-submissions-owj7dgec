class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> heap;
    int m_k{0};
    KthLargest(int k, vector<int>& nums) {
        this->m_k = k;
        for (int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
            if (heap.size()>k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size()>m_k) {
            heap.pop();
        }
        return heap.top();
    }
};
