class Solution {
public:
    vector<vector<int>> ret;
    set<int> vis;
    void solution(vector<int>& temp, vector<int>& nums){
        if (temp.size() == nums.size()){
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (vis.find(nums[i]) != vis.end()) continue;
            vis.insert(nums[i]);
            temp.push_back(nums[i]);
            solution(temp, nums);
            temp.pop_back();
            vis.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solution(temp, nums);
        return ret;
    }
};