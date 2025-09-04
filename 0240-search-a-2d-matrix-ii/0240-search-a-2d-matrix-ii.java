class Solution {
    boolean bsearch(int target, int[] matrix){
        int n = matrix.length;
        int st = 0;
        int en = n - 1;
        while (st <= en){
            int mid = (st + en) / 2;
            if (matrix[mid] < target) st = mid + 1;
            else if (matrix[mid] == target) return true;
            else en = mid - 1;
        }
        return false;
    }
  
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i < n; i++){
            if (matrix[i][0] <= target && target <= matrix[i][m-1]){
                if (bsearch(target, matrix[i])) return true;
            }
        }
        return false;
    }
}