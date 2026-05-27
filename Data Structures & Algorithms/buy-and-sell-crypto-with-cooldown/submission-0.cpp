class Solution {
public:

    int helper(int i,vector<int>& prices,int no_of_coins){

        if(i>=prices.size()) return 0;
        if(no_of_coins == 0){
            //hold hepler(i+1,prices,0)
           return max(helper(i+1,prices,0),helper(i+1,prices,1)-prices[i]);

            //buy helper(i+1,prices,1)-prices[i]
        }
         else{
            //hold hepler(i+1,prices,1)
            return max(helper(i+1,prices,1),helper(i+2,prices,0)+prices[i]);

            //sell helper(i+2,prices,0)+prices[i]
        }

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp_0(n+2,0);
        vector<int> dp_1(n+2,0);
        for(int i =n-1;i>=0;i--){
            dp_0[i]=max(dp_0[i+1],dp_1[i+1]-prices[i]);
            dp_1[i]=max(dp_1[i+1],dp_0[i+2]+prices[i]);
        }
        return dp_0[0];
        //return helper(0,prices,0);
                
    }
};
