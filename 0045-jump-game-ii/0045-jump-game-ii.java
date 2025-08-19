class Solution {
    public int jump(int[] nums) {
        //if (nums.length == 1) return 0;
        int cnt = 0;
        for (int i = nums.length - 1; i > 0; ){
            boolean flag = false;
            int temp = 0;
            for (int j = i - 1; j >= 0; j--){
                if (i - j <= nums[j]){
                    temp = j;
                    flag = true;
                }
            }
            if(flag) {
                cnt++;
                i = temp;
            }
            else i--;
        }
        return cnt;
    }
}