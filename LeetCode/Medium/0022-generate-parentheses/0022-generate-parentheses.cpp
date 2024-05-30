class Solution {
public:
    void dfs(string cur, int open_cnt, int close_cnt, vector<string>& result) {
	if (open_cnt == 0 && close_cnt == 0) {
		result.push_back(cur);
		return;
	}

	if (open_cnt > 0)
		dfs(cur + '(', open_cnt - 1, close_cnt, result);

	if (close_cnt > open_cnt)
		dfs(cur + ')', open_cnt, close_cnt - 1, result);
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ret;
        dfs("", n, n, ret);
        return ret;
    }
};