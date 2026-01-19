class Solution {
public:
    vector<vector<int>> ret;
    int N,K;
    void comb(int idx, vector<int> temp){
        if (temp.size() == K) {
            ret.push_back(temp);
            return;
        }
        for (int i = idx; i <= N; i++){
            temp.push_back(i);
            comb(i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        N = n; K = k;
        comb(1, {});
        return ret;
    }
};