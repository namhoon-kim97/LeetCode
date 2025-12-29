class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        for (int i = 0; i < t.size(); i++){
            if (t[i] == s[l]){
                l++;
            }
        }
        return l == s.size();
    }
};