class Solution {
public:
   void update(vector<int>& vec,int num,int val){
        //check i^th bit of num if 1 then update vec
        for(int i=0;i<32;i++){
            if((num>>i)&1)
                vec[i] += val;
        }
        
   }
     
   int numberFromvec(vector<int>& vec) {
      int num = 0;
      for(int i = 0; i < 32; i++) {
        if(vec[i] > 0)
            num = num | (1 << i);
      }
      return num;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
      int n = nums.size();
      int i = 0, j = 0;
      int res = INT_MAX;
      vector<int> vec(32, 0);
    
      while(j < n) {
          update(vec, nums[j], 1); // Update for the right end of the window
          while(i <= j && numberFromvec(vec) >= k) {
            res = min(res, j - i + 1); // Update result if condition is met
            update(vec, nums[i], -1); // Move left end of window
            i++;
          }
          j++;
      }
     return res == INT_MAX ? -1 : res;
    }
};