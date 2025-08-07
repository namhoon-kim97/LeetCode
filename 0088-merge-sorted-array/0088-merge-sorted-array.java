class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int midx = m - 1;
        int r = m + n - 1;
        int nidx = n - 1;
        while (nidx >= 0) {
                if (midx >= 0 && nums1[midx] > nums2[nidx]){
                    nums1[r--] = nums1[midx--];
                } else {
                    nums1[r--] = nums2[nidx--];
                }
        }
    }
}