class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            bool v = true;
            for(int j=i+1;j<p.size();j++){
                if(p[j]<=p[i]){
                    v = false;
                    ans.push_back(p[i]-p[j]);
                    break;
                }
            }
            if(v){
                ans.push_back(p[i]);
            }
        }
        return ans;
    }
};