class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        int rows = grid.size();
        int culs = grid[0].size();
        queue<pair<int,int>> q;
        int freshf = 0;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < culs;j ++) {
                if (grid[i][j] == 2){
                    q.push({i,j});
                }else if (grid[i][j] == 1) {
                    freshf++;
                }
            }
        }
        while(freshf>0 && !q.empty()){
            int size = q.size();
            for (int idx = 0; idx < size; idx++){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++){
                int newi = i+dir[k][0];
                int newj = j+dir[k][1];
                if (newi < 0 || newi >=rows || newj < 0 || newj >= culs || grid[newi][newj] != 1){
                    continue;
                }
                grid[newi][newj] = 2;
                freshf--;
                q.push({newi,newj});
            }
            }
            cnt++;
        }  
        return freshf == 0?cnt:-1; 
    }
};
