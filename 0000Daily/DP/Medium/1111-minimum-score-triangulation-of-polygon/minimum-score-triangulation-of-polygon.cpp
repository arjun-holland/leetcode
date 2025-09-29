// class Solution {
// public:
//     int solve(int i, int j, vector<int>& values) {
//         if (j - i < 2) return 0;  // Less than 3 vertices → no triangle possible

//         int minScore = INT_MAX;

//         // Try every possible point k between i and j
//         for (int k = i + 1; k < j; ++k) {
//             int score = values[i] * values[k] * values[j]
//                       + solve(i, k, values)
//                       + solve(k, j, values);
//             minScore = min(minScore, score);
//         }

//         return minScore;
//     }

//     int minScoreTriangulation(vector<int>& values) {
//         int n = values.size();
//         return solve(0, n - 1, values);
//     }
// // };

// Time complexity: Exponential O(2^n)
// Will time out for n > 20


// class Solution {
// public:
//     int solve(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
//         if (j - i < 2) return 0;
//         if (dp[i][j] != -1) return dp[i][j];

//         int minScore = INT_MAX;

//         for (int k = i + 1; k < j; ++k) {
//             int score = values[i] * values[k] * values[j]
//                       + solve(i, k, values, dp)
//                       + solve(k, j, values, dp);
//             minScore = min(minScore, score);
//         }

//         dp[i][j] = minScore;
//         return dp[i][j];
//     }

//     int minScoreTriangulation(vector<int>& values) {
//         int n = values.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return solve(0, n - 1, values, dp);
//     }
// };


class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
