class NumMatrix {
public:
    vector<vector<int>> vecmatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        vecmatrix.resize(matrix.size());
        for (int i=0; i < matrix.size(); i++) {
            int linesum = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                linesum+=matrix[i][j];
                vecmatrix[i].push_back(linesum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <=row2; i++) {
           int leftSum = (col1 > 0) ? vecmatrix[i][col1 - 1] : 0;

            res+=vecmatrix[i][col2]-leftSum;
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */