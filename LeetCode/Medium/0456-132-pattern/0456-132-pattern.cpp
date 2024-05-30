class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int min_num = INT32_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < min_num)
                return true;
            while (!st.empty() && st.top() < nums[i]){
                min_num = st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};