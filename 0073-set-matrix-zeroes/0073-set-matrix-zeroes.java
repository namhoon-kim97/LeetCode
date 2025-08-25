class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;

        int col0 = 1; // 첫 번째 열에 0이 있었는지 표시(0이면 첫 열을 나중에 0으로)
        // 1) 마킹: 첫 행은 matrix[0][j], 첫 열은 matrix[i][0]
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) col0 = 0; // 첫 열 플래그
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // 행 마크
                    matrix[0][j] = 0; // 열 마크
                }
            }
        }

        // 2) 뒤에서 앞으로 채우기: 마커에 따라 0 세팅
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // 첫 번째 열 처리(마지막에)
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
}
