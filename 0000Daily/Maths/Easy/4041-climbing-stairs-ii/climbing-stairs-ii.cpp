#define ll long long
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(),0);
        vector<ll> dp(n+1,LLONG_MAX); 
        dp[0] = 0;  //cost to react 0th index
        dp[1] = costs[1] + (1*1);

        for(int i=2;i<=n;i++){
            ll j1 = costs[i] + (i-(i-1))*(i-(i-1)) + dp[i-1];
            ll j2 = (i >= 2) ? costs[i] + (i-(i-2))*(i-(i-2)) + dp[i-2] : INT_MAX;
            ll j3 = (i >= 3) ? costs[i] + (i-(i-3))*(i-(i-3)) + dp[i-3] : INT_MAX;

            if(j1 <= j2 && j1 <= j3){
                dp[i] = j1;
            }else if(j2 <= j1 && j2 <= j3){
                dp[i] = j2;
            }else{
                dp[i] = j3;
            }
        }
        return dp[n];
    }
};