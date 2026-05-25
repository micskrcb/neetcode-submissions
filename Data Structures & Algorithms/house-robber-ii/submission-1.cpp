class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        if(n==0) return nums[0];
        vector<int> dp(n+1,-1);
        if(n>=1)dp[n-1]=nums[n-1];
        if(n>=2)dp[n-2]=max(nums[n-2],nums[n-1]);
        for(int i =n-3;i>=0;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
        //int ans = dp[0];
        //cout<<n<<endl;
        n++;
        if(n>=1)dp[n-1]=nums[n-1];
        if(n>=2)dp[n-2]=max(nums[n-2],nums[n-1]);
        for(int i =n-3;i>=1;i--){
            dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        }
       

        return max(dp[0],dp[1]);

    }
};
