class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // dp[i][j] will store the min path sum from triangle[i][j] to the bottom
        vector<vector<int>> dp = triangle;  // start with the triangle values

        // Start from the second last row and go upwards
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                // For each cell, choose the min of the two adjacent cells below
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        // The top element now contains the minimum path sum
        return dp[0][0];
    }
};


/*
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i,int it,vector<vector<int>>& t){
        if(t.size() == i){
            return 0;
        }
        if(dp[i][it] != INT_MAX)return dp[i][it];

        if(t[i].size() == it) return 0;

        int op1 = t[i][it] + solve(i+1,it, t);
        int op2 = t[i][it] + solve(i+1,it+1, t);

        dp[i][it] = min(op1,op2);
        return dp[i][it];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        dp.assign(n, vector<int>(m, INT_MAX));
        return solve(0, 0, triangle);
    }
};
*/


/* 
//BRUTE FORCE 1 - RECURSION
class Solution {
public:
    int ans = INT_MAX;
    void solve(int i,int it,vector<vector<int>>& t,int cs){
        if(t.size() == i){
            ans = min(ans, cs);
            return;
        }
        if(t[i].size() == it) return;
        cs += t[i][it];
        solve(i+1,it, t, cs);
        solve(i+1,it+1, t, cs);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        solve(0, 0, triangle, 0);
        return ans;
    }
};
*/

/*
//BRUTE FORCE 2 - RECURSION
class Solution {
public:
    int solve(int i, int it, vector<vector<int>>& t) {
        // Base case: if we've reached the bottom of the triangle
        if (i == t.size()) {
            return 0;
        }

        // Get current value and recursively find the min path sum
        int down = solve(i + 1, it, t);
        int diag = solve(i + 1, it + 1, t);

        return t[i][it] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle);
    }
};
*/

/*
class Solution {
public:
    int solve(int i, int it, vector<vector<int>>& t) {
        if (i == t.size()) {
            return 0;
        }
        if (it == t[i].size()) return 0;

        int ans = INT_MAX;
        int down = solve(i + 1, it, t);
        int diag = solve(i + 1, it + 1, t);

        return ans = t[i][it] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0, 0, triangle);
    }
};
*/