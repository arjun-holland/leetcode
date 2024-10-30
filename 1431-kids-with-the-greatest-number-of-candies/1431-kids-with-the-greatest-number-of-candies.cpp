class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> b;
        for(int &c:candies){
            int t = c+extraCandies;
            int m = *max_element(candies.begin(),candies.end());
            if(t>=m)b.push_back(true);
            else b.push_back(false);
        }
        return b;
    }
};