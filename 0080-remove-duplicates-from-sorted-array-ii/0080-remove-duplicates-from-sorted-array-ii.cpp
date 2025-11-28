class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int l = 0;
        int r = l + 1;
        int cnt = 1;

        while (r < n){
            while (r < n && cnt >= 2 && nums[l] == nums[r]) r++;
            if (r >= n) break;

            if (nums[l] == nums[r]) cnt++;
            else cnt = 1;
            
            nums[l+1] = nums[r];
            l++;
            r++;
        }
        return l + 1;
    }
};