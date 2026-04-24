class Solution {
public:
    int maxv = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int cul = grid[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < cul; j++) {
                if (grid[i][j] == 1){
                    maxv = max(maxv,backtrace(i,j,grid));
                }
            }
        }
        return maxv;
    }
    int dirlist[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int backtrace(int i,int j,vector<vector<int>>& grid){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        int res = 1;
        grid[i][j] = 0;

        res += backtrace(i+dirlist[0][0],j+dirlist[0][1],grid);
        res +=backtrace(i+dirlist[1][0],j+dirlist[1][1],grid);
        res+=backtrace(i+dirlist[2][0],j+dirlist[2][1],grid);
        res+=backtrace(i+dirlist[3][0],j+dirlist[3][1],grid);
        return res;
    }
};
