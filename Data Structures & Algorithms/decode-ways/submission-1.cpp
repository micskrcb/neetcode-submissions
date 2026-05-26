class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        int n = s.size();
        if(s[n-1]!='0')dp[n-1]=1;
        dp[n]=1;
        for(int i =n-2;i>=0;i--){
            if(s[i]!='0')dp[i]=dp[i+1];
            if(s[i]=='1'){
                dp[i]+=dp[i+2];
            }
            if(s[i]=='2' && s[i+1]<='6'){
                dp[i]+=dp[i+2];
            }
        }
        for(auto a: dp){
            cout<<a<<" ";
        }
        cout<<endl;
        return dp[0];
        
    }
};
