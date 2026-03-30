class Solution {
public:
    int maxArea(vector<int>& heights) {
                int res =0;
        int l = 0;
        int r = heights.size()-1;
        while( l < r) {
            int cur = (r-l) * min(heights[r], heights[l]);
            res = max(res,cur);
            if ( heights[l] <= heights[r]) {
                l++;
            }else 
                r--;
        }
        return res;
    }
};
