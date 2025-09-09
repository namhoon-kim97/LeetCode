class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        if (n < 3) return 0;
        int dp = 0;
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp = dp + 1;
            } else {
                dp = 0;
            }
            ans += dp;
        }
        return ans;
    }
}