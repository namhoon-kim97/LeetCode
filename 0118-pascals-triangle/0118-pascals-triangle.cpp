class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.resize(numRows);
        for (int i = 1; i <= numRows; i++){
            ret[i - 1].resize(i);
            ret[i-1][0] = 1;
            ret[i-1][i-1] = 1;
            for (int j = 1; j <= i - 2; j++){
                ret[i-1][j] = ret[i-2][j-1] + ret[i-2][j];
            }
        }
        return ret;
    }
};