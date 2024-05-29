class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp(3);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];

            int st = i + 1;
            int en = nums.size() - 1;
            while (st < en) {
                int sum = nums[st] + nums[en];
                if (sum == target) {
                    temp[0] = -target;
                    temp[1] = st;
                    temp[2] = en;
                    ret.push_back({nums[i], nums[st], nums[en]});
                    while (st < en && nums[st] == nums[st + 1]) st++;
                    while (st < en && nums[en] == nums[en - 1]) en--;
                    st++;
                    en--;
                }
                else if (sum > target)
                    en--;
                else
                    st++;
            }
        }
        return ret;
    }
};