class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int l = 0, r = m-1;
        Integer inRow = null;
        while(l<=r){
            int mid = (l+r)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                inRow = mid;
                break;
            }
            else if(target < matrix[mid][0]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        if(inRow == null)
            return false;
        
        l = 0;
        r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target == matrix[inRow][mid])
                return true;
            else if(target < matrix[inRow][mid])
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
}