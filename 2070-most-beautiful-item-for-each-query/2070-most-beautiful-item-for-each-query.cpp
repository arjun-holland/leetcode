class Solution {
public:
     int customBinarySearch(vector<vector<int>>& items, int queryPrice) {
        int l = 0;
        int r = items.size()-1;

        int mid;
        int maxBeauty = 0;

        while(l <= r) {
            mid = l + (r-l)/2;

            if(items[mid][0] > queryPrice) {
                r = mid-1; //ignore current and right side items. Move to left now.
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid+1;
            }
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
       /*
        vector<int> ans;     
        for(int &q:queries){  //tc : O(q*n) ==> 10^5*10^5=10^10 crossed the constraints
            int re  = 0;
            for(int i=0;i<items.size();i++){  //linear search
                if(items[i][0] > q){
                    continue;
                }else{
                    re = max(re,items[i][1]);
                }
            }
            ans.push_back(re);
        }
        return ans;
        */
        int n = items.size();   
        int m = queries.size();
        
        vector<int> result(m);
        //step-1 : Sort the array based on price in asencind order
        sort(begin(items), end(items)); //{pricei, beautyi}   tc : O(nlogn)
        
        int maxBeautySeen = items[0][1]; //building prefix sum for buity in items array
        for(int i = 1; i < n; i++) {                          //tc : O(n)
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }

        for(int i = 0; i < m; i++) {           //tc : O(mlogn) binary search finds element in log(n) time complexity
            int queryPrice = queries[i];
            result[i] = customBinarySearch(items, queryPrice);
        }

        return result;
    }
};