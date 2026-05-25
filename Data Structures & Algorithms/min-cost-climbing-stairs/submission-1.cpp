class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1,-1);
        dp[n]=0;
        if(n>=1)dp[n-1]= cost[n-1];
        if(n>=2)dp[n-2]=cost[n-2];
        for(int i =n-3;i>=0;i--){
            dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);        
    }
    int helper(vector<int>& cost,int i ){
        int n = cost.size();
        if(i>=n) return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=cost[i]+min(helper(cost,i+1),helper(cost,i+2));
    }

};
