class Solution {
public:
    vector<vector<int>> direc = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix,int i,int j,int pre) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        if (i < 0 || i >= ROWS || j < 0 || j >=COLS || 
            matrix[i][j] <= pre) 
            return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int res = 1;
        for (vector<int> d : direc) {
            int newi = i+d[0];
            int newd = j+d[1];
            if (newi<0 || newi>=ROWS || newd < 0 || newd >=COLS || matrix[newi][newd] <= pre) continue;
            res = max(res,1+dfs(matrix,i+d[0],j+d[1],matrix[i][j]));
        }
        dp[i][j] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        dp.resize(rows,vector<int>(cols,-1));
        int LIP = 0;
        for (int r = 0; r <rows; r++) {
            for (int j = 0; j < cols; j++) {
                LIP = max(LIP,dfs(matrix,r,j,INT_MIN));
            }
        }    
        return LIP;
    }
};
