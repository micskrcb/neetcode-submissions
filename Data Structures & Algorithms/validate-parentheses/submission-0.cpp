class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto a : s){
            if(a =='('||a=='{'||a=='['){
                st.push(a);
            }
            if(a=='}'){
                if(st.empty())return false;
                else {
                    char c = st.top();
                    st.pop();
                    if(c!='{') return false;
                }
            }
            if(a==')'){
                if(st.empty())return false;
                else {
                    char c = st.top();
                    st.pop();
                    if(c!='(') return false;
                }
            }
            if(a==']'){
                if(st.empty())return false;
                else {
                    char c = st.top();
                    st.pop();
                    if(c!='[') return false;
                }
            }
        }
        return st.empty();
        
    }
};
