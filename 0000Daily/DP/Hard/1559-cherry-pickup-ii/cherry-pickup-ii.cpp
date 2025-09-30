class Solution {
public:
    int dp[71][71][71];
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