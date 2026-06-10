class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s:tokens){
            char a = s[0];
            if(isdigit(a) || s.size()>1){
                st.push(stoi(s));
            }
            else{
                int num2 = st.top();
                    st.pop();
                    int num1= st.top();
                    st.pop();
                if(a=='+'){
                    st.push(num1+num2);             
                }
                 if(a=='-'){
                    st.push(num1-num2);             
                }
                 if(a=='*'){
                    st.push(num1*num2);             
                }
                 if(a=='/'){
                    st.push(num1/num2);             
                }
            }
        }
        return st.top();        
    }
};
