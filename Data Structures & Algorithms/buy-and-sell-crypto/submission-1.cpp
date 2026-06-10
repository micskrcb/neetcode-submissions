class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int l = 0;
        int r = 1;

        if(prices.size()<=1) return 0;

        while(r<prices.size()){
            ans = max(ans,prices[r]-prices[l]);
            if(prices[l]>prices[r])l=r;
            r++;
        }
        return ans;
        
    }
};
