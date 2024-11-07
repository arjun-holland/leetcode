class Solution {
public:
    int largestCombination(vector<int>& candidates) {
  //constraints : 1 <= candidates[i] <= 10^7 
  //No.of bits required to represent a number 10^7 is ln(10^2)+1==24
        int ans = 0;
        for(int i=0;i<24;i++){
            int count = 0;
            for(int &n : candidates){
                if( (n&(1<<i)) != 0)
                    count++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};