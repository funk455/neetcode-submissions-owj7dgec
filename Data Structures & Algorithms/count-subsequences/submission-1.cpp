class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n<m) return 0;
        dp.assign(n+1,vector<int>(m+1,-1));
        return dfs(s,t,0,0);
    }
    int dfs(string s, string t,int i,int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = dfs(s,t,i+1,j);
        if(s[i] == t[j])
            res+=dfs(s,t,i+1,j+1);
        dp[i][j] = res;
        return res;
    }
};
