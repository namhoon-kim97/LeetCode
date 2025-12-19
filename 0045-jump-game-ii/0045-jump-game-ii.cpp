class Solution {
public:
    int d[10001];
    int jump(vector<int>& nums) {
        int n = nums.size();
        fill(d, d + n, INT_MAX);
        if (n < 2) return 0;
        d[0] = 0;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] >= i - j)
                    d[i] = min(d[i], d[j] + 1);
            }
        }
        // for (int i = 0; i < n; i++)
        //     cout << d[i] << ' ';
        return d[n-1];
    }
};