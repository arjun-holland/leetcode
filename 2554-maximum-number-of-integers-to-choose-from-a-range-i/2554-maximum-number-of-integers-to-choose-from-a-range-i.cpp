class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int r = 0,cs = 0;
        set<int> s(banned.begin(),banned.end());
        for(int i=1;i<=n;i++){    //Tc : O(n) ans sc :O(n)
            if(s.count(i) != 0){
                continue;
            }
            else if(cs+i <= maxSum){
               cs += i;
                r++;
            }else{
                break;
            }
        }
        return r;
    }
};