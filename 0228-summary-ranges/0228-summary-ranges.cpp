class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() < 1) 
            return ret;
        
        int st = nums[0];
        int en = -2147483648;
        for (int i = 1; i < nums.size(); i++){
            if ((long long)nums[i] - (long long)nums[i-1] > (long long)1){
                if (st < en)
                    ret.push_back(to_string(st) + "->" + to_string(en));
                else 
                    ret.push_back(to_string(st));
                st = nums[i];
                en = -2147483648;
            }
            else en = nums[i];
        }
        if (st >= en)
            ret.push_back(to_string(st));
        else ret.push_back(to_string(st) + "->" + to_string(en));
        
        return ret;
    }
};