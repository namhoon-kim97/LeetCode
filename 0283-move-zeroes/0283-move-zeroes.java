class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int st = 0;
        while (st < n - 1 && nums[st] != 0) st++;
        int en = st + 1;
        while (st < n){
            while (en < n && nums[en] == 0) en++;
            if (nums[st] == 0 && en < n){
                int temp = nums[st];
                nums[st] = nums[en];
                nums[en] = temp;
            }
            st++;
        }
    }
}