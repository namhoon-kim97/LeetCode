class Solution {
    public int maxArea(int[] height) {
        int st = 0;
        int en = height.length - 1;

        int ans = 0;
        while (st < en){
            int area = 0;
            if (height[st] < height[en]){
                area = (en - st) * height[st];
                st++;
            } else {
                area = (en - st) * height[en];
                en--;
            }
            ans = Math.max(ans,area);
        }
        return ans;
    }
}