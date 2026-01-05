class Solution {
public:
    vector<string> split(string s){
        vector<string> ret;
        size_t it;
        size_t cur = 0;
        while ((it = s.find(' ', cur)) != string::npos){
            ret.push_back(s.substr(cur, it - cur));
            cur = it + 1;
        }
        ret.push_back(s.substr(cur));
        return ret;
    }

    bool wordPattern(string pattern, string s) {
        vector<string> v = split(s);
        if (v.size() != pattern.size()) return false;
        unordered_map<char, string> um1;
        unordered_map<string, char> um2;
        for (int i = 0; i < pattern.size(); i++){
            if (um1.find(pattern[i]) != um1.end() && um1[pattern[i]] != v[i]) return false;
            if (um2.find(v[i]) != um2.end() && um2[v[i]] != pattern[i]) return false;
            um1[pattern[i]] = v[i];
            um2[v[i]] = pattern[i];
        }
        return true;
    }
};