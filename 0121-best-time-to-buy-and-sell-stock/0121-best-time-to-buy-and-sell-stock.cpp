class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int ans = 0;
        int l = 0;
        int r = 1;
        int n = prices.size();
        while (r < n){
            if (prices[l] >= prices[r]){
                l=r; r++;
            } else {
                ans = max(ans,prices[r] - prices[l]);
                r++;
            }
        }
        return ans;
    }
};