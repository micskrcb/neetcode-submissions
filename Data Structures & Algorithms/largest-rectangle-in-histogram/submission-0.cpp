class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> nge(n);
        vector<int> pge(n);

        int ans=0;
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }
            else nge[i]=st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=0;i<n;i++){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pge[i]=-1;
            }
            else pge[i]=st.top();
            st.push(i);
        }

        for(int i =0;i<n;i++){
            ans = max(ans,heights[i]*(nge[i]-pge[i]-1));
        }

        return ans;

    }
};
