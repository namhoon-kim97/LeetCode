class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n = s1.length();
        int m = s2.length();
        if (n + m != s3.length()) return false;
        Boolean[][] dp = new Boolean[n+1][m+1]; // dp[i][j] = s1 i개와 s2 j개를 해서 s3의 i+j개가 되는가?
        return dfs(0,0,s1,s2,s3,dp);
    }
    boolean dfs(int i, int j, String s1, String s2, String s3, Boolean[][] dp){
        if (i == s1.length() && j == s2.length()) return true;
        if (dp[i][j] != null) return dp[i][j];

        int k = i + j;
        boolean ok = false;
        if (i < s1.length() && s1.charAt(i) == s3.charAt(k))
            ok = dfs(i+1,j,s1,s2,s3,dp);
        if (!ok && j < s2.length() && s2.charAt(j) == s3.charAt(k))
            ok = dfs(i,j+1,s1,s2,s3,dp);
        return dp[i][j] = ok;
    }
}