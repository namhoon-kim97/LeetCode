class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int l = 0;
        int r = l + 1;
        while (r < nums.size() && l < r){
            // 같으면 같이 증가
            // 다르면 r이 r+1이랑 다를때까지 증가
            // l = r 넣음
            // l++, r++
            while (r < nums.size() && nums[l] == nums[r]){ 
                r++;
            }
            if (r >= nums.size()) break;
            
            nums[l+1] = nums[r];
            l++; r++;

            // 0 0 1 1 1 2 2 3 3 4
            // 0 1 1 1 1 2 2 3 3 4
            // 
        }
        return l+1;
    }
};