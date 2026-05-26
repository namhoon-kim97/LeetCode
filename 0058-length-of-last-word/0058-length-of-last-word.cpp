class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        while (s[n - 1] == ' ') n--;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') break;
            cnt++;
        }
        return cnt;
    }
};