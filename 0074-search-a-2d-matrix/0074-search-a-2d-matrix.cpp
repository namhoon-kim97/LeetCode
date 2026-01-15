class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st = 0;
        int en = (n * m) - 1;

        while (st <= en){
            int mid = (st + en) / 2;
            if (matrix[mid / m][mid % m] < target) st = mid + 1;
            else if (matrix[mid / m][mid % m] > target) en = mid - 1;
            else return true;
        }
        return false;
    }
};