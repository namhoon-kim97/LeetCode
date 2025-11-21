class Solution {
    public int removeElement(int[] nums, int val) {
        int l = 0;
        int r = nums.length - 1;

        while (l <= r) {
            while (l <= r && nums[l] != val) l++;
            while (l <= r && nums[r] == val) r--;

            if (l > r) break;

            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;

            l++;
            r--;
        }

        return l;
    }
}