class MinStack {
public:
    stack<int> mnst;
    stack<int> st;
    MinStack() {
      
    }
    
    void push(int val) {
        st.push(val);
       // if(!mnst.empty())
        if(mnst.empty() || val <= mnst.top()){
    mnst.push(val);
}       
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if(!mnst.empty())
        if(val==mnst.top()){
            mnst.pop();
        }

    }
    
    int top() {
        return st.top();        
    }
    
    int getMin() {
        return mnst.top();
    }
};
