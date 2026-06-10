class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l =0;
        int r=0;
        int ans =0;


        vector<bool> mp(256,false);
        
        while(r<n){
            cout<<l<<r<<endl;
            char curr= s[r];
            while(mp[curr]){
                mp[s[l]]=false;
                l++;
            }
            mp[curr]=true;
            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
        
    }
};
