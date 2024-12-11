class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int x  = nums[i];
            int y = x + 2*k;   // y <= x+2k
            
            int j = binarysearch(nums,0,nums.size()-1,y);
            res = max(res,j-i+1); 
        }
        return res;
    }
    int binarysearch(vector<int>& nums,int s,int e,int t){
        int re = s;
        while(s<=e){
          int m = s+(e-s)/2;
          if(nums[m] <= t){
              s = m+1;
              re = max(re,m);
          }else{
              e = m-1;
          }
        }
        return re;
    }
};