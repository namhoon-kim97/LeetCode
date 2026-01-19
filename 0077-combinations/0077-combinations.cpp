class Solution {
public:
    vector<vector<int>> ret;
    set<int> vis;
    void comb(int idx, int cnt, vector<int> temp, int n){
        if (cnt == 0) {
            ret.push_back(temp);
            return;
        }
        for (int i = idx; i <= n; i++){
            if (vis.find(i) != vis.end()) continue;
            vis.insert(i);
            temp.push_back(i);
            comb(i, cnt - 1, temp,n);
            temp.pop_back();
            vis.erase(i);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        comb(1,k, {}, n);
        return ret;
    }
};