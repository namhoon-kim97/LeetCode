class Solution {
public:
    bool isPalindrome(string s) {
        std::string out;
        out.reserve(s.size());

        for (unsigned char c : s) {
            if (std::isalnum(c)) {
                out.push_back(std::tolower(c));
            }
        }

        int l = 0;
        int r = out.size() - 1;
        while (l < r) {
            if (out[l] != out[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};