class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row_l = -1, row_r = m;
        while(row_r - row_l > 1){
            int row_m = (row_r + row_l)/2;
            if(target < matrix[row_m][0])
                row_r = row_m;
            else if(target > matrix[row_m][n-1])
                row_l = row_m;
            else{
                auto found = *lower_bound(matrix[row_m].begin(), matrix[row_m].end(), target);
                if(found == target)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};