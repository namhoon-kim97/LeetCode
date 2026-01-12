class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        if (nums.size() == 0 ) return 0;
        dp[0] = nums[0];
        if (nums.size() == 1) return nums[0];
        dp[1] = nums[1];
        if (nums.size() == 2) return max(dp[0], dp[1]);
        for (int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            for (int j = 0; j < i - 2; j++)
                dp[i] = max(dp[i], dp[j] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};