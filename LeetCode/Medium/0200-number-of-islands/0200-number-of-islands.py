class Solution(object):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        vis = [[False] * len(grid[0]) for _ in range(len(grid))]
        cnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if vis[i][j] or grid[i][j] == "0":
                    continue
                if grid[i][j] == "1":
                    self.bfs(i, j, grid, vis)
                    cnt += 1
        return cnt

    def bfs(self, i, j, grid, vis):
        q = deque()
        q.append((i, j))
        while q:
            x, y = q.popleft()
            for dir in range(4):
                nx = x + self.dx[dir]
                ny = y + self.dy[dir]
                if nx < 0 or ny < 0 or nx >= len(grid) or ny >= len(grid[0]):
                    continue
                if vis[nx][ny] or grid[nx][ny] == "0":
                    continue
                vis[nx][ny] = True
                q.append((nx, ny))