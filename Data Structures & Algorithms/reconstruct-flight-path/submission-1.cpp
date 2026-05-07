class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 构建图，用 multiset 处理重复的边
        map<string, multiset<string>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> result;
        dfs(graph, result, "JFK");
        
        // 反转因为我们从末尾开始添加
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(map<string, multiset<string>>& graph, 
             vector<string>& result, const string& src) {
        
        // 贪心：按字典序尝试所有目的地（multiset 自动排序）
        while (!graph[src].empty()) {
            string dest = *graph[src].begin();
            graph[src].erase(graph[src].begin());  // 删除已使用的边
            dfs(graph, result, dest);
        }
        
        // 添加到结果末尾，最后反转
        result.push_back(src);
    }
};