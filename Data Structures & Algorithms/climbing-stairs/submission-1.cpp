class Solution {
public:
    vector<long long> dp;
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        if(n<0) return 0;
        if(n==0)return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=helper(n-1)+helper(n-2);        
    }
    int helper(int n) {
        //dp.resize(n+1,-1);
        if(n<0) return 0;
        if(n==0)return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=climbStairs(n-1)+climbStairs(n-2);        
    }
};
