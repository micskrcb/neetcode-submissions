class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        if(prices.size()==0) return 0;
        int min_price = prices[0];
        for(auto a: prices){
            profit = max(a-min_price,profit);
            min_price = min(min_price,a);
        }
        return profit;
        
    }
};
