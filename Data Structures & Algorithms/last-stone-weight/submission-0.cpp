class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> heap;
       for (auto & s : stones) {
        heap.push(s);
       } 
       while (heap.size()>1) {
        int f = heap.top();
        heap.pop();
        int s = heap.top();
        heap.pop();
        if (s < f) {
            heap.push(f-s);
        }
       }
       heap.push(0);
       return heap.top();
    }
};
