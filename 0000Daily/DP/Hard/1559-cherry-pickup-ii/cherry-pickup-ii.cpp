 
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(C, 0)));

        // Base case: last row
        for (int j1 = 0; j1 < C; ++j1) {
            for (int j2 = 0; j2 < C; ++j2) {
                if (j1 == j2)
                    dp[R - 1][j1][j2] = grid[R - 1][j1];
                else
                    dp[R - 1][j1][j2] = grid[R - 1][j1] + grid[R - 1][j2];
            }
        }

        // Fill from R-2 to 0
        for (int i = R - 2; i >= 0; --i) {
            for (int j1 = 0; j1 < C; ++j1) {
                for (int j2 = 0; j2 < C; ++j2) {
                    int maxChoco = -1e9;
                    for (int dj1 = -1; dj1 <= 1; ++dj1) {
                        for (int dj2 = -1; dj2 <= 1; ++dj2) {
                          int nj1 = j1 + dj1;
                          int nj2 = j2 + dj2;
                          if (nj1 >= 0 && nj1 < C && nj2 >= 0 && nj2 < C) {
                            int value = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
                            value += dp[i + 1][nj1][nj2];
                            maxChoco = max(maxChoco, value);
                          }
                        }
                    }
                    dp[i][j1][j2] = maxChoco;
                }
            }
        }
        return dp[0][0][C - 1];   
    }
};

/*
class Solution {
public:
    int dp[71][71][71]; //r c c 
    int solve(int i,int j1,int j2,vector<vector<int>>& g){
        int r = g.size();
        int c = g[0].size();

        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)return INT_MIN;
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

        if(i == r-1){
            if(j1 == j2)return g[i][j1];
            return g[i][j1] + g[i][j2];
        }
        int ans = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2)value = g[i][j1];
                else value = g[i][j1] + g[i][j2];

                int next = solve(i+1,j1 + dj1,j2 + dj2,g);
                int cur = value + ((next != INT_MIN) ? next : 0);
                ans = max(ans,cur);
            }
        }
        return dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        memset(dp, -1, sizeof(dp)); 
        return solve(0,0,c-1,grid);
    }
};
*/
//TC : O(r * c²) // memoization + Recursion
//SC : O(r * c²)
//TC : Time = O(r * c * c * 9^r)   // ❌ exponential time pure recurssion
