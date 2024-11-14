//TC : O(NlogM)   
class Solution {
public:
    // Function to check if it's possible to distribute quantities with a maximum of 'x' per shop
    bool possibleToDis(int x, vector<int>& quantities, int shops){
        for(int &q : quantities){   // O(N)
             // Calculate how many shops are needed for the current quantity with a max capacity of 'x'
            shops -= (q+x-1)/x;    //ceil(q/x);
            if(shops < 0)          // If we run out of shops, return false
                return false;
        }
        return  true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(),quantities.end());
        int res = 0;
        
        while(l<=r){     //O(logM)
            int m = l+(r-l)/2;
            if(possibleToDis(m,quantities,n)){
                res = m;
                r = m-1;      // Try for a smaller maximum
            }else{
                l = m+1;      // Increase the minimum limit
            }
        }
        return res;
    }
};