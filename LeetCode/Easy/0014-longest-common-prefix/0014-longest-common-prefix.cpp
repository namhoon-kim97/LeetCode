class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if (strs.size() < 2)
	        return strs[0];
        int cnt = 0;
        while (true) {
            char a;
            for (int i = 0; i < strs.size() - 1; i++) {
                if (!strs[i][cnt])
                    return ret;
                if (strs[i] == "")
                    return ret;
                if (strs[i][cnt] == strs[i + 1][cnt]) {
                    a = strs[i][cnt];
                }
                else
                    return ret;
            }
            ret += a;
            cnt++;
        }
        return ret;
    }
};