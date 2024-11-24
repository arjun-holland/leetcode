class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long s = 0;    // total sum
        int tn = 0;         // total negative numbers
        int sn = INT_MAX;   // smallest negative number

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s += abs(matrix[i][j]);
                if (matrix[i][j] < 0) {
                    tn++;
                }
               sn = min(sn, abs(matrix[i][j]));
            }
        }

        if (tn % 2 == 0) {
            return s;   // if tn is even then return s
        }
        return s - 2 * sn;
    }
};