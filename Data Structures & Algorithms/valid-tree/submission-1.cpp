class Solution {
public:
    set<int> visiting;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size()> n-1) return false;
        vector<vector<int>> adjlist(n);
        for( auto couple : edges){
            adjlist[couple[0]].push_back(couple[1]);
            adjlist[couple[1]].push_back(couple[0]);
        }
            if (!dfs(0,-1,adjlist))
                return false;
        return visiting.size()==n;
    }
    bool dfs(int cur, int prev,vector<vector<int>> adjlist){
        if (visiting.count(cur)){
            return false;
        }
        visiting.insert(cur);
        for (auto next : adjlist[cur]){
            if (next == prev)
                continue;
            if (!dfs(next,cur,adjlist))
                return false;
        }
        return true;
    }
};
