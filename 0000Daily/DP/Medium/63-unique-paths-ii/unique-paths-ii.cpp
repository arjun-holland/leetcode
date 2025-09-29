class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size();
        int m = og[0].size();

        // If the starting or ending cell is an obstacle, return 0
        if (og[0][0] == 1 || og[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Starting point
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (og[i][j] == 1) {
                    dp[i][j] = 0; // Can't go through obstacles
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};
