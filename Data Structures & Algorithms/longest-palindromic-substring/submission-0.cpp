class Solution {
public:
    string longestPalindrome(string s) {
        int l = -1;
        //int r = -1;
        int sz = 0;

     string r="#";
     for(auto a:s){
        r+=a;
        r+='#';
     }
     string ans = "";
     int n = r.size();
     for(int i =0;i<r.size();i++){
        int st=i;
        int nd =i;
        while(st-1>=0 && nd+1<n && r[st-1]==r[nd+1]){
            st--;
            nd++;            
        }
        if(nd-st+1>sz){
            sz = nd-st+1;
            l = st;
        }
     }
     for(int i =l;i<=l+sz-1;i++){
       if(r[i]!='#') ans+=r[i];
     }
     return ans;




    }
};
