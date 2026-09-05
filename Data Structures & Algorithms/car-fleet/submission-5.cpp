class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> st;
        vector<pair<int,int>> arr;
        for(int i =0;i<position.size();i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        for(int i =0;i<position.size();i++){
            double p = arr[i].first;
            double s = arr[i].second;
            //cout<<p<<" "<<s<<endl;
            if(st.empty())st.push({p,s});
            else{
                double pos = st.top().first;
                double sp = st.top().second;
                while((pos-target)/sp>=(p-target)/s && !st.empty()){
                     
                    st.pop();
                    if(st.empty()) break;
                    pos = st.top().first;
                    sp = st.top().second;
                }
                st.push({p,s});
            }
        }
         int ans = st.size();
            // while(!st.empty()){
            //     cout<<st.top().first<<" ";
            //     cout<<st.top().second<<endl;
            //     st.pop();
            // }
        return ans;
    }
};
