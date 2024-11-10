class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{
                if(!st.empty()){
                    char ch = st.top();
                    if(ch=='(' && c==')')st.pop();
                    else if(ch=='[' && c==']')st.pop();
                    else if(ch=='{' && c=='}')st.pop();
                    else return false;
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};