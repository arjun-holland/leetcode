class Solution {
public:
    int strStr(string ha, string ne) {
        if(ha.size()<ne.size())
            return -1;
        int re = -1;
        for(int i=0;i<=ha.size()-ne.size();i++){
            int k=i,j=0;
            while(j<ne.size() && k<ha.size() && ha[k] == ne[j]){
                if(j == ne.size()-1){
                    re=i;
                    return re;
                }
                k++;
                j++;
            }
        }
        return -1;
    }
};