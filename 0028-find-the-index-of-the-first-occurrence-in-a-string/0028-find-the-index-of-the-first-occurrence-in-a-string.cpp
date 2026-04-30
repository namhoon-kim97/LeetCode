class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++){
            if (haystack[i] == needle[0]){
                int cur = i;
                bool flag = true;
                for (int j = 0; j < needle.size(); j++) {
                    if (haystack[cur++] != needle[j]) flag = false;
                    if (cur == haystack.size()) break;
                }
                if (flag) return i;
            }
        }
        return -1;
    }
};