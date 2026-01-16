class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ret = INT_MAX;
        int sum = nums[0];
        int l = 0;
        int r = 0;
        while (l < n && r < n) {
            if (sum >= target) {
                ret = min(ret, r - l + 1);
                if (sum == target) {
                    sum -= nums[l];
                    l++;
                    r++;
                    sum += nums[r];

                } else {
                    sum -= nums[l];
                    l++;
                }
            } else {
                r++;
                if (r < n) sum += nums[r];
            }
        }
        if (ret == INT_MAX)
            return 0;
        return ret;
    }
};