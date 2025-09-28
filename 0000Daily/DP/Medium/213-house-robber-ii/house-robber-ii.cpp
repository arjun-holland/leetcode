#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1) return nums[start];

        vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: Rob from 0 to n-2 (exclude last house)
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2: Rob from 1 to n-1 (exclude first house)
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
