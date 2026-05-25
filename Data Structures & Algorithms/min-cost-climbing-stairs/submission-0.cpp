class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n+1,-1);
        dp[n]=0;
        return min(helper(cost,0),helper(cost,1));        
    }
    int helper(vector<int>& cost,int i ){
        int n = cost.size();
        if(i>=n) return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=cost[i]+min(helper(cost,i+1),helper(cost,i+2));
    }

};
