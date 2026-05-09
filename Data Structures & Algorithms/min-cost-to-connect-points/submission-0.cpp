class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<bool> visited(N, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        pq.push({0, 0});  // {cost, index}
        int totalCost = 0;
        
        while (!pq.empty()) {
            auto [cost, i] = pq.top();
            pq.pop();
            
            if (visited[i]) continue;
            visited[i] = true;
            totalCost += cost;
            
            // 添加所有未访问邻居
            for (int j = 0; j < N; j++) {
                if (!visited[j]) {
                    int dist = abs(points[i][0] - points[j][0]) + 
                              abs(points[i][1] - points[j][1]);
                    pq.push({dist, j});
                }
            }
        }
        return totalCost;
    }
};