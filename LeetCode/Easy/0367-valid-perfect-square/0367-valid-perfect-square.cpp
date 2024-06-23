class Solution {
public:
    bool isPerfectSquare(int num) {
        for (unsigned long i = 1; i * i <= num; i++) {
            if (num % i == 0 && i == num / i)
                return true;
        }
        return false;
    }
};