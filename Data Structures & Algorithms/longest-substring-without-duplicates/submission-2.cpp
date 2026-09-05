class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        set<char> st;
        map<char,int> mp;
        int ans = 0;

        for(r=0;r<n;r++){
            char curr = s[r];
            st.insert(curr);
            mp[curr]++;
            if(st.size()!=r-l+1){
                mp[s[l]]--;
                if(mp[s[l]]==0)st.erase(s[l]);
                l++;
            }
            else{
                ans = r-l+1;
            }

            

        }
        return ans;


        
    }
};
