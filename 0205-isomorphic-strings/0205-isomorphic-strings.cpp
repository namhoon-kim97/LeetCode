class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um1;
        unordered_map<char,char> um2;
        for (int i = 0; i < s.size(); i++){
            um1[s[i]] = t[i];
            um2[t[i]] = s[i];
        }
        for (int i = 0; i < s.size(); i++){
            if (um2[t[i]] != s[i] || um1[s[i]] != t[i]) return false;
        }
        return true;
    }
};