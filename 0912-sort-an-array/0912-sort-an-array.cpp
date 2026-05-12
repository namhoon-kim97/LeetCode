class Solution {
public:
    void conquer(vector<int>& nums, int st, int mid, int en) {
        vector<int> temp;
        int k = mid;
        int i = st;
        while (st < k && mid < en) {
            if (nums[st] > nums[mid]) temp.push_back(nums[mid++]);
            else temp.push_back(nums[st++]);
        }
        while (st < k) {
            temp.push_back(nums[st++]);
        }
        while (mid < en) {
            temp.push_back(nums[mid++]);
        }
        for (int a : temp) {
            nums[i++] = a; 
        }
    }
    void divide(vector<int>& nums, int st, int en) {
        if (en - st <= 1) return;
        int mid = (st + en) / 2;
        divide(nums, st, mid);
        divide(nums, mid, en);
        conquer(nums, st, mid, en);
    }
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size());
        return nums;
    }
};