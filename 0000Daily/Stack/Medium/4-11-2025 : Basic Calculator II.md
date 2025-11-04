# Problem
<img width="1286" height="360" alt="image" src="https://github.com/user-attachments/assets/103040b7-2bb3-4598-ae44-b5b3d78b72fd" />
<img width="779" height="408" alt="image" src="https://github.com/user-attachments/assets/6851963d-1232-4431-9419-9072e6b5c314" />
<img width="1032" height="295" alt="image" src="https://github.com/user-attachments/assets/42ef7125-6cd8-4475-8e50-99fd005badaa" />

# Intuition
![WhatsApp Image 2025-11-04 at 07 40 26_4dded114](https://github.com/user-attachments/assets/20bea97e-4e49-4917-8020-e092c9dccd0e)

```
Pattern in stack :  while the current_operation is mathematical operator ,
                    perform the last_operation you have taken
                    and update the last_operation with the current_operation
```

<img width="795" height="365" alt="image" src="https://github.com/user-attachments/assets/1f60b8c3-0bd8-4547-9109-e2b320630581" />


```
take Global values : Last_operation_performed = '+', num = 0
Track the ch char of String :
    if ch == dight:
        num = ch
    else ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch = string.length()-1 :
        if(operation == '+') stack.push(num)
        else if(operation == '-') stack.push(-num)
        else if(operation == '*') {
            first = st.top(), st.pop()
            second = num
            st.push(first * second)
        }
        else if(operation == '/') {
            first = st.top(), st.pop()
            second = num
            st.push(first / second)
        }
        operation = ch
        num = 0

res = 0
until stack is empty :
    res += stack.top()
    stack.pop()

return res
```

![WhatsApp Image 2025-11-04 at 07 37 07_19785afe](https://github.com/user-attachments/assets/abc2f298-a90b-4262-80f3-8ad0f360fe45)
![WhatsApp Image 2025-11-04 at 07 37 21_ab6e0855](https://github.com/user-attachments/assets/c90f7559-38d6-4c62-868b-d2040aff6817)
![WhatsApp Image 2025-11-04 at 07 37 49_032cb4f4](https://github.com/user-attachments/assets/2fc9bd99-1fdd-4629-a6ea-6138396cdbd9)


# Code
```
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int op = '+';  //default operator

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(isdigit(ch))num = num * 10 + (ch-'0');

            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || i == s.length()-1 ){
                if(op == '+')st.push(num);
                else if(op == '-')st.push(-num);
                else if(op == '*'){
                    int t = st.top();
                    st.pop();
                    st.push(t * num);
                }
                else if(op == '/'){
                    int t = st.top();
                    st.pop();
                    st.push(t / num);
                }
                op = ch;
                num = 0;
            }
        }

        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
```

Leetcode : 227
