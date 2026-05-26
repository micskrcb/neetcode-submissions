class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(long long i =0;i<=amount;i++){
            for(auto a: coins){
                if(i+a<=amount && dp[i]!=INT_MAX){
                    dp[i+a]=min(dp[i+a],1+dp[i]);
                }
            }
        }
        if(dp[amount]==INT_MAX)return -1;
        else return dp[amount];
    }
};
