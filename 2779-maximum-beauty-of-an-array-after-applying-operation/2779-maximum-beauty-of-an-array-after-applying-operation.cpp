class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,int>> in; //for intervals
        for(int e : nums){
            in.push_back({e-k,e+k});
        }
        sort(in.begin(),in.end());
        int res = INT_MIN;
        deque<pair<int,int>> dq;
        for(auto p:in){
            if(!dq.empty() && dq.front().second < p.first){
                dq.pop_front();
            }
            dq.push_back(p);
            res = max(res,(int)dq.size());
        }
        return res;
    }
};