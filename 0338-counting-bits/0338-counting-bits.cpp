class Solution {
public:
    vector<int> countBits(int n) {
       /* vector<int> r;         //TC:O(n) SC:O(n)
        for(int i=0;i<=n;i++){
            int nb = __builtin_popcount(i);
            r.push_back(nb);
        }
        return r;*/
        std::vector<int> res(n + 1, 0); // Initialize a vector of size n+1 with all values set to 0
        
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1); // Use bitwise operations to fill the array
        }
        
        return res; // Return the result array
    }
};