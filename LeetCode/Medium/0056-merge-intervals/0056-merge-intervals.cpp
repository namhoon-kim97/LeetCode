class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });
        vector<vector<int>> ret;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size() ; ++i) {
            if (prev[1] >= intervals[i][0]) {
                prev[1] = max(prev[1], intervals[i][1]);
            }
            else {
                ret.push_back(prev);
                prev = intervals[i];
            }
        }

        ret.push_back(prev);
        return ret;
    }
};