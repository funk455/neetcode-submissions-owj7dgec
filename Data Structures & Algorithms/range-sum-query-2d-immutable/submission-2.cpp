class NumMatrix {
public:
    vector<vector<int>> prematrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prematrix = vector<vector<int>>(n+1,vector<int>(m+1,0));
        for (int row = 0; row < n; row++) {
            int sum = 0;
            for (int cul = 0; cul < m; cul++) {
                sum+=matrix[row][cul];
                int above = prematrix[row][cul+1];
                prematrix[row+1][cul+1] = above+sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int buttomright = prematrix[row2][col2];
        int above = prematrix[row1-1][col2];
        int left = prematrix[row2][col1-1];
        int topleft = prematrix[row1-1][col1-1];
        return buttomright - above - left + topleft;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */