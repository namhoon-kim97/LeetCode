class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;
        vector<int> ret;
        for (int a : nums1) {
            um[a] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (um[nums2[i]]) {
                ret.push_back(nums2[i]);
                um[nums2[i]]--;
            }
        }
        return ret;
    }
};