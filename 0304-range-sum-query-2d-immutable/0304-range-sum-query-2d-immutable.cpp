class NumMatrix {
public:
    vector<vector<int>> mat_sum;
    int m;
    int n;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        mat_sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        /*
        for(int i=1; i<m; i++){
            mat_sum[i][1] = mat_sum[i-1][1] + matrix[i-1][0];
        }
        for(int i=1; i<n; i++){
            mat_sum[1][i] = mat_sum[1][i-1] + matrix[0][i-1];
        }
        */
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                mat_sum[i][j] = matrix[i-1][j-1] + mat_sum[i-1][j] + mat_sum[i][j-1] - mat_sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        
        return mat_sum[row2][col2] - mat_sum[row2][col1-1] - mat_sum[row1-1][col2] + mat_sum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */