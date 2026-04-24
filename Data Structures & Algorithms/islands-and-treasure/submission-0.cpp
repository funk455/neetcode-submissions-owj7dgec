class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if ( grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        int dirvec[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k =0; k < 4; k++) {
                int r = i+dirvec[k][0];
                int c = j+dirvec[k][1];
                if ( r < 0 || r >= m || c < 0 || c >= n || grid[r][c]!=INT_MAX){
                    continue;
                }
                grid[r][c] = grid[i][j]+1;
                q.push({r,c});
            }
        }
        
    }
};
