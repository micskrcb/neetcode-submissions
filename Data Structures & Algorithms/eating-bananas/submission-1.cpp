class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long l = 1;
        long long r = 10e9;

        long long ans = 10e9;

        while(l<=r){
            long long mid = l+(r-l)/2;
            long long temp = 0;
            for(int i =0;i<piles.size();i++){
                temp += piles[i]/mid;
                if(piles[i]%mid) temp++;
            }
            if(temp <=h){ans =mid;
            r=mid-1;}
            else l= mid+1;
        }
        return ans;


    }
};
