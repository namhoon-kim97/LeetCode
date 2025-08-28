class Solution {
    public int maximumGap(int[] nums) {
        int n = nums.length;
        if (n < 2) return 0;

        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int x : nums) {
            min = Math.min(min, x);
            max = Math.max(max, x);
        }
        if (min == max) return 0;

        int bucketSize = (int) Math.max(1, Math.ceil((double)(max - min) / (n - 1)));
        int bucketCount = (max - min) / bucketSize + 1;

        int[] bucketMin = new int[bucketCount];
        int[] bucketMax = new int[bucketCount];
        boolean[] used = new boolean[bucketCount];
        for (int i = 0; i < bucketCount; i++) {
            bucketMin[i] = Integer.MAX_VALUE;
            bucketMax[i] = Integer.MIN_VALUE;
        }

        for (int x : nums) {
            int idx = (x - min) / bucketSize;
            bucketMin[idx] = Math.min(bucketMin[idx], x);
            bucketMax[idx] = Math.max(bucketMax[idx], x);
            used[idx] = true;
        }

        int ans = 0;
        int prevMax = -1;
        for (int i = 0; i < bucketCount; i++){
            if (!used[i]) continue;
            if (prevMax != -1){
                ans = Math.max(ans, bucketMin[i] - prevMax);
            }
            prevMax = bucketMax[i];
        }
        return ans; 
    }
}