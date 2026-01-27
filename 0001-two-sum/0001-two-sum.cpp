class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            for (int j = i + 1; j < nums.size(); j++){
                if (cur + nums[j] == target) return {i,j};
            }
        }
        return {};
    }
};