class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int l =1;int r = n-1;
        while(l<=r){
            if(l==r)return l;
            int mid = (l+r)/2;
            int cnt =0;
            for(auto a:nums){
                if(l<=a && mid>=a)cnt++;
            }
            if(mid-l+1>=cnt){
                    l=mid+1;
                }
            else{
                r=mid;
            }
                
        }
        
    }
};
