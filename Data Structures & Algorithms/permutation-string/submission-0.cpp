class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l =0;
        int r =s1.size()-1;
       vector<int> mp(256,0);
       vector<int> m(256,0);
       for(auto a: s1){
        m[a-'a']++;
       }
       if(s2.size()<s1.size())return 0;
       for(int i =0;i<s1.size();i++){
        m[s2[i]-'a']--;
       }
       if(m==mp)return true;

       while(r<s2.size()-1){
        r++;
        m[s2[l]-'a']++;
        l++;
        m[s2[r]-'a']--;
        if(m==mp)return true;
       }






        return false;



    }
};
