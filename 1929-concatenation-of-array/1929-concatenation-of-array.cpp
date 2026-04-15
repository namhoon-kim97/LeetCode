class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        ret.resize(2*n);
        for (int i = 0; i < n; i++){
            ret[i] = nums[i];
            ret[i+n] = nums[i];
        }
        return ret;
    }
};