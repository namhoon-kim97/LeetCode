class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> ret;
        int cur = 0;
        if (strs.size() == 1) return strs[0];
        while (true){
            for (int i = 0; i < strs.size() - 1; i++){
                if (cur == strs[i].size()) return std::string(ret.begin(), ret.end());
                if (strs[i][cur] != strs[i+1][cur]) return std::string(ret.begin(), ret.end());
            }
            ret.push_back(strs[0][cur]);
            cur++;
        }
        return std::string(ret.begin(), ret.end());
    }
};