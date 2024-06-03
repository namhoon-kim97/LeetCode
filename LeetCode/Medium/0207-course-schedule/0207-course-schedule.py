class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) < 2:
            return True
        adj = [[] * numCourses for _ in range(numCourses)]
        indegree = [0] * numCourses
        q = deque()
        for i, j in prerequisites:
            indegree[i] += 1
            adj[j].append(i)

        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        arr = []
        while q:
            cur = q.popleft()
            arr.append(cur)
            for i in adj[cur]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.append(i)

        if len(arr) == numCourses:
            return True
        return False