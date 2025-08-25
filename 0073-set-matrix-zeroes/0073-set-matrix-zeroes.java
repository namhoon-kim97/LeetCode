class Solution {
    public void setZeroes(int[][] matrix) {
        Queue<int[]> q = new LinkedList<>();
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i <n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) q.add(new int[]{i,j});    

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int nx = x;
            while (nx >= 0){
                matrix[nx][y] = 0;
                nx--;
            }
            nx = x;
            while (nx < n){
                matrix[nx][y] = 0;
                nx++;
            }
            int ny = y;
            while (ny >= 0){
                matrix[x][ny] = 0;
                ny--;
            }
            ny = y;
            while (ny < m){
                matrix[x][ny] = 0;
                ny++;
            }
        }
    }
}