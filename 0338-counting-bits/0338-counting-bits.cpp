class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> r;
        for(int i=0;i<=n;i++){
            int nb = __builtin_popcount(i);
            r.push_back(nb);
        }
        return r;
    }
};