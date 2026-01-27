class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um; // value -> idx
        for (int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            auto it = um.find(need);
            if (it != um.end()) return {it->second, i};
            um[nums[i]] = i;
        }
        return {};
    }
};