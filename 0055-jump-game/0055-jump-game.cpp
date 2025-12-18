class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        if (nums[0] == 0) return false;

        // 현재 값 줄이면서 가다가 현재 값보다 크면 갱신
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++){
            cur--;
            if (cur < 0) return false;
            if (cur < nums[i]) cur = nums[i];
        }
        return true;        
    }
};