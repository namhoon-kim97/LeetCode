class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> um;
        while (true){
            int temp = 0;
            vector<int> digits;
            while (n > 0) {
                digits.push_back(n % 10);
                n /= 10;
            }
            for (int a : digits){
                temp += (a * a);
            }
            n = temp;
            if (n == 1) return true;
            if (um[n]) return false;
            um[n] = true;
        }
        return false;
    }
};