class Solution {
public:
    bool vis[301][301];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int N, M;
    void bfs(int x, int y, vector<vector<char>>& grid){
        vis[x][y] = true;
        queue<pair<int,int>> q;
        q.push({x,y});
        while (!q.empty()){
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (vis[nx][ny] || grid[nx][ny] == '0') continue;
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        int ret = 0;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    ret++;
                    bfs(i,j, grid);
                }
            }
        }
        return ret;
    }
};