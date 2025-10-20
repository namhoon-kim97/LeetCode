class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ret = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        while (i >= 0 && j >= 0){
            int cur = (a[i] - '0') + (b[j] - '0') + carry;
            ret += to_string(cur % 2);
            carry = cur / 2;
            i--;
            j--;
        }
        while(i >= 0){
            int cur = a[i] - '0' + carry;
            ret += to_string(cur % 2);
            carry = cur / 2;
            i--;
        }
        while(j >= 0){
            int cur = b[j] - '0' + carry;
            ret += to_string(cur % 2);
            carry = cur / 2;
            j--;
        }
        if (carry > 0)
            ret += to_string(carry);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};