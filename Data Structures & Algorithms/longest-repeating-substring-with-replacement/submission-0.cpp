class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        //max_count +k >= r-l+1
        vector<int> frq(26);
        int max_count = 0;
        int ans = 0;

        for(r = 0;r<n;r++){
            char curr = s[r];
            frq[curr-'A']++;
            max_count = max(frq[curr-'A'],max_count);
            if(max_count+k < r-l+1){
                frq[s[l]-'A']--;
                l++;
            }
            else ans = r-l+1;
            //cout<<l<<" "<<r<<" "<<max_count<<" "<<endl;

        }
        return ans;

        
    }
};
