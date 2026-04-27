class Solution {
public:
    int rows;
    int culs;
    void solve(vector<vector<char>>& board) {
        //起点as long as satisf x>0 x<row-1 y>0 y<cul-1 就进入dfs
        rows = board.size();
        culs = board[0].size();
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O'){
                capture(r,0,board);
            }
            if (board[r][culs-1] == 'O'){
                capture(r,culs-1,board);
            }
        }
        for (int c = 0; c < culs; c++) {
            if (board[0][c] == 'O'){
                capture(0,c,board);
            }
            if (board[rows-1][c] == 'O'){
                capture(rows-1,c,board);
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < culs; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
    void capture(int r, int c,vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= rows ||
            c >= culs || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';
        capture(r + 1, c,board);
        capture(r - 1, c,board);
        capture(r, c + 1,board);
        capture(r, c - 1,board);
    }
};
