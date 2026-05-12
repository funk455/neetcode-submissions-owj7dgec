class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        // {cost, node, stops}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> q;
        q.push({0, src, 0});
        
        // 记录到达每个节点时"用过的最少停留数"
        vector<int> minStops(n, INT_MAX);
        
        while (!q.empty()) {
            auto [cost, node, stops] = q.top();
            q.pop();
            
            if (node == dst) return cost;        // 优先队列首次出队即最优
            if (stops > k) continue;             // 超出停留限制
            if (stops >= minStops[node]) continue; // ← 关键剪枝：相同/更多停留没意义
            minStops[node] = stops;
            
            for (auto& [next, price] : adj[node]) {
                q.push({cost + price, next, stops + 1});
            }
        }
        
        return -1;
    }
};