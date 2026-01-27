class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um; // value -> idx
        for (int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if (um.count(need)) return {um[need], i};
            um[nums[i]] = i;
        }
        return {};
    }
};