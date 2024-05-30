class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int st = 0;
        int max_len = INT32_MIN;
        for (int i = 0; i < s.length(); i++){
            if (map[s[i]])
                st = max(st, map[s[i]]);

            map[s[i]] = i + 1;
            max_len = max(max_len, i - st + 1);
        }
        return max_len < 0 ? 0 : max_len;
    }
};