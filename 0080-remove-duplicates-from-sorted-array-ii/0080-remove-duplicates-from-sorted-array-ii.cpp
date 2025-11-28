class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> um;
        int l = 0;
        int r = l + 1;
        int n = nums.size();
        while (r < n){
            while (r < n && um[nums[l]] == 1 && nums[l] == nums[r]) r++;
            if (r >= n) break;
            um[nums[l]]++;
            nums[l+1] = nums[r];
            l++;
            r++;
            
        }
        return l + 1;
    }
};