class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int N, M;
    bool vis[201][201];
    void bfs(int x, int y, vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        vis[x][y] = true;
        q.push({x, y});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (vis[nx][ny] || board[nx][ny] == 'X')
                    continue;
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        N = n;
        M = m;
        // first row
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                bfs(0, j, board);
            }
        }
        // last row
        for (int j = 0; j < m; ++j) {
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                bfs(n - 1, j, board);
            }
        }
        // first col
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                bfs(i, 0, board);
            }
        }
        // last col
        for (int i = 0; i < n; ++i) {
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                bfs(i, m - 1, board);
            }
        }

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
