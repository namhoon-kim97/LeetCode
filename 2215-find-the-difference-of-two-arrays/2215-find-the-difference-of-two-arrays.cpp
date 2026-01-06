class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;

        for (int a : nums1)
            s1.insert(a);
        for (int a : nums2)
            s2.insert(a);

        vector<int> diff1, diff2;
        for (int x : s1) {
            if (s2.find(x) == s2.end())
                diff1.push_back(x);
        }

        for (int x : s2) {
            if (s1.find(x) == s1.end())
                diff2.push_back(x);
        }
        return {diff1, diff2};
    }
};