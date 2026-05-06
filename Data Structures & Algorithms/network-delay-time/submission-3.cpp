class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& t : times){
            graph[t[0]].push_back({t[1], t[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});
        
        set<int> visited;
        int maxTime = 0;
        
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            
            if(visited.count(node)) continue;
            visited.insert(node);
            maxTime = time;
            
            for(auto& [next, w] : graph[node]){
                if(!visited.count(next)){
                    pq.push({time + w, next});
                }
            }
        }
        
        return visited.size() == n ? maxTime : -1;
    }
};