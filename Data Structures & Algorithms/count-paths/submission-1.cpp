class Solution {
public:
    int dfs(vector<vector<int>> &cache,int i,int j,int m, int n) {
        if (i>=m || j>=n) return 0;
        if (i==m-1 && j==n-1) return 1;
        if (cache[i][j]) return cache[i][j];
        return cache[i][j] = dfs(cache,i+1,j,m,n) + dfs(cache,i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m,vector<int>(n,0));
        cache[m-1][n-1] = 1;
        return dfs(cache,0,0,m,n);
    }
};
