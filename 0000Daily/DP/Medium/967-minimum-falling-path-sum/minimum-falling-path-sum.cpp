/*
class Solution {
public:
    int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
        if(row == A.size()-1)
            return A[row][col];
        if(t[row][col] != -1)
            return t[row][col];
        
        int minSum = INT_MAX;
        
        for(int shift = -1; shift<=1; shift++) {
            if(col + shift >=0 && col+shift < A[row].size()) {
                minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
            }
        }
        
        return t[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(); //row
        int n = m; //column
        vector<vector<int>> t(101, vector<int>(101,-1));
        
        int result = INT_MAX;
        for(int col = 0; col<n; col++) {
            result = min(result, MFS(A, 0, col, t));
        }
        return result;
    }
};
*/


/*
class Solution {
public:
    int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
        if (row == A.size() - 1)
            return A[row][col];

        if (t[row][col] != -1)
            return t[row][col];

        int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

        if (col - 1 >= 0)
            op1 = A[row][col] + MFS(A, row + 1, col - 1, t);

        op2 = A[row][col] + MFS(A, row + 1, col, t);

        if (col + 1 < A[row].size())
            op3 = A[row][col] + MFS(A, row + 1, col + 1, t);

        int minAns = min({op1, op2, op3});

        return t[row][col] = minAns;
    }

    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(); // rows
        int n = A[0].size(); // columns

        vector<vector<int>> t(m, vector<int>(n, -1));

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, MFS(A, 0, col, t));
        }

        return result;
    }
};
*/


// class Solution {
// public:
//     int MFS(vector<vector<int>>& A) {
//         int m = A.size();
//         vector<vector<int>> t(m, vector<int>(m,0));
        
//         //initialization
//         for(int col = 0; col<m; col++) {
//             t[0][col] = A[0][col];
//         }
        
//         for(int row = 1; row < m; row++) {
//             for(int col = 0; col < m; col++) {
//                 t[row][col] = A[row][col] + min({t[row-1][col], 
//                                                  t[row-1][max(0, col-1)], 
//                                                  t[row-1][min(m-1, col+1)]});
//             }
//         }

//         return *min_element(t[m-1].begin(), t[m-1].end());
        
//     }
//     int minFallingPathSum(vector<vector<int>>& A) { 
//         return MFS(A);
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();

        // Work from second-last row up to the top
        for (int row = m - 2; row >= 0; row--) {
            for (int col = 0; col < m; col++) {
                int down = A[row + 1][col];
                int leftDiag = (col > 0) ? A[row + 1][col - 1] : INT_MAX;
                int rightDiag = (col < m - 1) ? A[row + 1][col + 1] : INT_MAX;

                A[row][col] += min({down, leftDiag, rightDiag});
            }
        }

        // The answer will be the min value in the top row
        return *min_element(A[0].begin(), A[0].end());
    }
};
