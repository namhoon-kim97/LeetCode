class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++){
            while(!dq.empty() && dq.back().first <= nums[i]) dq.pop_back();
            dq.push_back({nums[i],i});
            if (i - k + 1 < 0) continue;
            while (!dq.empty() && dq.front().second <= i-k) dq.pop_front();
            ret.push_back(dq.front().first);
        }
        
        return ret;
    }
};