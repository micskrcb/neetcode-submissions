class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int n  = nums.size();
        // vector<int> dp_min(n);
        // vector<int> dp_max(n);
        // dp_min[0]=nums[0];
        // dp_max[0]=nums[0];
        int curr_min,prev_min=nums[0],curr_max,prev_max=nums[0];
        int ans = nums[0];

        for(int i =1;i<n;i++){
            if(nums[i]<0){
                curr_min=min(nums[i]*prev_max,nums[i]);
                curr_max=max(nums[i]*prev_min,nums[i]);
            }
            if(nums[i]>=0){
                curr_min=min(nums[i]*prev_min,nums[i]);
                curr_max=max(nums[i]*prev_max,nums[i]);
            }
            ans = max(ans,curr_max);
            prev_max = curr_max;
            prev_min = curr_min;
            
        }
        return ans;


        
    }
};
