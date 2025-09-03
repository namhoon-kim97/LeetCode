class Solution {
    int n = 0;
    boolean dfs(int i, List<String> wordDict, String s, Boolean[] dp){
        if (i == n) return true;
        if (dp[i] != null) return dp[i];
        for (String word : wordDict) {
            if (word.length() + i > n) continue;
            if (s.startsWith(word, i)) {
                if (dfs(i + word.length(), wordDict,s, dp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false; 
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        n = s.length();
        Boolean[] dp = new Boolean[n + 1];
        return dfs(0, wordDict,s,dp);
    }
}