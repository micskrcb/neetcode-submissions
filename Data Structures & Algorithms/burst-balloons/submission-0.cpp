class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n + 2, 1);
        for (int i = 0; i < n; i++)
            temp[i + 1] = nums[i];

        vector<vector<int>> dp(n + 2,
                               vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;

                for (int k = i; k <= j; k++) {
                    int left = (k > i) ? dp[i][k - 1] : 0;
                    int right = (k < j) ? dp[k + 1][j] : 0;

                    dp[i][j] = max(
                        dp[i][j],
                        left + right +
                        temp[i - 1] * temp[k] * temp[j + 1]
                    );
                }
            }
        }

        return dp[1][n];
    }
};