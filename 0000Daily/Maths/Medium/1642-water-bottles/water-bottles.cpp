class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(true){
            if(numBottles < numExchange)break;
            int wfb = numBottles / numExchange;
            int wnfb = numBottles % numExchange;

            ans += wfb;
            numBottles = wfb + wnfb;
        }
        return ans;
    }
};