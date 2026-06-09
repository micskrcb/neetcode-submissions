class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        unordered_map<int,int> lc;
        int ans = 0;

        for(auto a: nums){
            if(mp[a])continue;
            else{
                mp[a]=true;
                lc[a]=1+lc[a-1]+lc[a+1];
                
                if(mp.count(a-1)) lc[a-lc[a-1]] = lc[a];
                if(mp.count(a+1)) lc[a+lc[a+1]] = lc[a];
                ans = max(ans,lc[a]);
            }
        }
        // for(auto a:lc){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        return ans;

        
        
    }
};
