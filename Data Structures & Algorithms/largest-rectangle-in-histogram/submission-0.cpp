class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxa = 0;
        stack<pair<int,int>> stack;
        for ( int i = 0; i < heights.size(); i++) {
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]) {
                pair<int,int> top = stack.top();
                int index = top.first;
                int height = top.second;
                maxa = max(maxa,height*(i-index));
                stack.pop();
                start = index;
            }
            stack.push({start,heights[i]});
        }
        //clear ---expand to right
        while ( !stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            maxa = max(maxa,height*(static_cast<int>(heights.size())-index));
            stack.pop();
        }
        return maxa;
    }
};
