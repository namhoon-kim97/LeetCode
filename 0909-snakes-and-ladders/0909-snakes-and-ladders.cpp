class Solution {
public:
    pair<int,int> convert(int n, int num){
        int quot = (num - 1) / n;
        int rem  = (num - 1) % n;
        int row = n - quot - 1;
        int col = (quot % 2 == 0) ? rem : (n - 1 - rem);
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n*n + 1);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        int cnt = 0;
        while (!q.empty()){
            int size = q.size();
            while (size--){
                int cur = q.front(); q.pop();
                if (cur == n * n) return cnt;
                for (int i = 1; i <= 6; i++){
                    int next = cur + i;
                    if (next > n * n) continue;
                    pair<int,int> nextCO = convert(n, next);

                    if (board[nextCO.first][nextCO.second] != -1)
                        next = board[nextCO.first][nextCO.second];
                    
                    if (!vis[next]){
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
            cnt++;
        }
        return -1;   
    }
};