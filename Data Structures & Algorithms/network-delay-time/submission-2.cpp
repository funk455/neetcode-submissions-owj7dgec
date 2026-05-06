class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 构建邻接表
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& t : times){
            graph[t[0]].push_back({t[1], t[2]});
        }
        
        // min heap: (时间, 节点)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            
            if(time > dist[node]) continue;
            
            for(auto& [next, w] : graph[node]){
                if(time + w < dist[next]){
                    dist[next] = time + w;
                    pq.push({time + w, next});
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};