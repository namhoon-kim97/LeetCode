class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> um;
        for (int i = 0; i < nums.size(); i++){
            um[nums[i]].push_back(i);
        }
        int l = 0;
        int r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (l < r){
            int sum = nums[l] + nums[r];
            if (sum > target) r--;
            else if (sum < target) l++;
            else {
                vector<int> ret;
                if (nums[l] == nums[r]){
                    return um[nums[l]];
                } else {
                    return {um[nums[l]][0], um[nums[r]][0]};
                }
            }
        }
        return {};
    }
};