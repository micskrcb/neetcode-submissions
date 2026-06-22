class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        if(dp[i][j]!=-1)return dp[i][j];
        vector<pair<int,int>> v({{i-1,j},{i,j-1},{i+1,j},{i,j+1}});
        int temp =0;
        for(auto[a,b]:v){
            if(a>=0 && b>=0 && a<n && b<m){
                if(matrix[a][b]>matrix[i][j]){
                    temp = max(temp,dfs(a,b,dp,matrix));
                }
            }
        }
        return dp[i][j]=temp+1;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                dfs(i,j,dp,matrix);
                ans = max(dp[i][j],ans);
            }
        }
        return ans;

        
    }
};
