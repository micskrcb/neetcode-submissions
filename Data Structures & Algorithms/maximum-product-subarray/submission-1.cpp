class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int n  = nums.size();
        vector<int> dp_min(n);
        vector<int> dp_max(n);
        dp_min[0]=nums[0];
        dp_max[0]=nums[0];
        int ans = nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]<0){
                dp_min[i]=min(nums[i]*dp_max[i-1],nums[i]);
                dp_max[i]=max(nums[i]*dp_min[i-1],nums[i]);
            }
            if(nums[i]>=0){
                dp_min[i]=min(nums[i]*dp_min[i-1],nums[i]);
                dp_max[i]=max(nums[i]*dp_max[i-1],nums[i]);
            }
            ans = max(ans,dp_max[i]);
            cout<<i<<" :"<<dp_max[i]<<" , "<<dp_min[i]<<endl;
        }
        return ans;


        
    }
};
