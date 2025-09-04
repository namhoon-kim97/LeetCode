class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        Set<Integer> ret = new HashSet<>();
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ret.add(matrix[i][j]);
            }
        }
        return ret.contains(target);
    }
}