class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()!=b.length()){
            while(a.length()>b.length()){
                b.insert(0, "0");
            }
             while(b.length()>a.length()){
                a.insert(0, "0");
            }
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        char carry = '0';
        string res = "" ;
        for(int i=0; i<a.size(); i++){
            if(a[i]=='0' && b[i]=='0' && carry == '0' )res.push_back('0');
            else if((a[i]=='1' && b[i]=='1' && carry == '0')||(a[i]=='0' && b[i]=='1' && carry == '1')||(a[i]=='1' && b[i]=='0' && carry == '1')){
                res.push_back('0');
                carry = '1';
            }
            else if(a[i]=='1' && b[i]=='1' && carry == '1'){
                res.push_back('1');
                carry = '1';
            }
            else{
                res.push_back('1');
                if(carry == '1')carry ='0';
            }
        }
        if(carry=='1') res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};