class Solution {
public:
    bool possible(int m ,vector<int>& p,int h){
        
        for(int &ep : p){
            h -= (ep+m-1)/m;//ceil(ep/m)
            if(h<0)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r = *max_element(piles.begin(),piles.end());
        int re =0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(possible(m,piles,h)){
                re = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return re;
    }
};