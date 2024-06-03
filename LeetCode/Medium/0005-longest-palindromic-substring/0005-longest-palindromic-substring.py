class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        d = [[False] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j]:
                    if j - i >= 2:
                        if d[i + 1][j - 1]:
                            d[i][j] = True
                    else:
                        d[i][j] = True

        max_sub = 0
        ret = [0, 0]
        for i in range(n):
            for j in range(n - 1, -1, -1):
                if d[i][j]:
                    if max_sub < (j - i):
                        max_sub = j - i
                        ret[0] = i
                        ret[1] = j

        return s[ret[0] : ret[1] + 1]
