class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> v(26,0);
        for(char& e : s){
            v[e -'a']++ ;
        }
        string res ;
        int i=25;
        while(i>=0){
            if(v[i] == 0){
                i--;
                continue;
            }
            int el = min(v[i],repeatLimit);
            char e = 'a'+i;
            res.append(el,e);
            v[i] = v[i]-el;
            if(v[i] > 0){
                int j = i-1;
                while(j>=0 && v[j] == 0){
                    j--;
                }
                if(j<0)break;
                res.push_back('a'+j);
                v[j] = v[j] - 1;
            }
        }
        return res;
    }
};