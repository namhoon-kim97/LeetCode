class Solution {
    List<List<String>> ret = new ArrayList<>();
    List<String> s = new ArrayList<>();
    int[] queens = new int[10];
    int N;
    
    public boolean promising(int row){
        for(int i = 0; i < row; i++){
            if (queens[row] == queens[i]) return false;
            else if (Math.abs(row - i) == Math.abs(queens[row] - queens[i])) return false;
        }
        return true;
    }

    String buildRow(int col){
        char[] row = new char[N];
        Arrays.fill(row, '.');
        row[col] = 'Q';
        return new String(row);
    }

    public void dfs(int row){
        if (row == N){
            ret.add(new ArrayList<>(s));
            return;
        }
        for (int i = 0; i < N; i++){
            queens[row] = i;
            if (promising(row)){
                s.add(buildRow(i));
                dfs(row + 1);
                s.remove(s.size() - 1);
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        N = n;
        dfs(0);
        return ret;
    }
}