class Solution {
public:
    int n;
    int t[100001][3];
    int binarySearch(vector<vector<int>>& events,int ei){
        int l =0;
        int r = n-1;
        int res = n;
        while(l <= r){
            int m = l + ( r-l)/2;
            if(events[m][0] > ei){
                res = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return res;
    }
    
    int solve(vector<vector<int>>& events,int i,int c){
        if(c == 2 || i >= n)
            return 0;
        if(t[i][c] != -1)
            return t[i][c];
        int vin = binarySearch(events,events[i][1]);
        int take = events[i][2] + solve(events,vin,c+1);
        
        int ntake = solve(events,i+1,c);
        
        return t[i][c] =  max(take,ntake);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        memset(t,-1,sizeof(t));
        sort(events.begin(),events.end());
        return solve(events,0,0);
    }
};