class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int T,B,L,R;
        T = 0;
        B = matrix.size()-1;//total no.of rows
        L = 0;
        R = matrix[0].size()-1;//total no .of columns
        int d = 0;   //direction
        vector<int> ans;
        
        while(T<=B && L<=R){
            if(d == 0){                  //left to right
                for(int i=L;i<=R;i++){    //TOP SIDE TRAVERSAL
                    ans.push_back(matrix[T][i]);
                }
                T++;   //Increment TOP SIDE TRAVERSAL
            }
            else if(d == 1){               //top to bottom
                for(int i=T;i<=B;i++){      //RIGHT SIDE TRAVERSAL
                    ans.push_back(matrix[i][R]);
                }
                R--;    //Decrement RIGHT SIDE TRAVERSAL
            }
            else if(d == 2){                //right to left
                for(int i=R;i>=L;i--){      //BOTTOM SIDE TRAVERSAL
                    ans.push_back(matrix[B][i]);
                }
                B--;      //Decrement BOTTOM SIDE TRAVERSAL
            }
            else if(d == 3){            //bottom to top
                for(int i=B;i>=T;i--){   //LEFT SIDE TRAVERSAL
                    ans.push_back(matrix[i][L]);
                }
                L++;      //Increment LEFT SIDE TRAVERSAL
            }
            d++;
            d = d % 4;
        }
        return ans;
    }
};