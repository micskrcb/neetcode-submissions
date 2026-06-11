class Solution {
public:
    vector<vector<bool>> dp;

    bool helper(int i,int j,string& s1, string& s2, string& s3){
        if(i==s1.size()&&j==s2.size())return true;
        //if(dp[i][j]!=-1)return dp[i][j];
        int k = i+j;
        bool ans = false;
        if(i<s1.size() && s1[i]==s3[k])ans=ans || helper(i+1,j,s1,s2,s3);
        if(j<s2.size() && s2[j]==s3[k])ans=ans || helper(i,j+1,s1,s2,s3);
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size()+1,vector<bool>(s2.size()+1,false));
        if(s1.size()+s2.size()!=s3.size())return false;
        // return helper(0,0,s1,s2,s3);  
        dp[0][0]=true;
        for(int i =0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                int k = i+j-1;
                if(i>0 && s1[i-1]==s3[k])dp[i][j]=dp[i][j] || dp[i-1][j];
                if(j>0 && s2[j-1]==s3[k])dp[i][j]=dp[i][j] || dp[i][j-1];
                //cout<<dp[i][j]<<" ";
            }
           // cout<<"\n";
        }
        return dp[s1.size()][s2.size()];     
    }
};
