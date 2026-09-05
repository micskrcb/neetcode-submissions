class Solution {
public:
    int findMin(vector<int> &nums) {

        int l = 0;
        int r = nums.size()-1;
        int ans=nums[0];

        while(l<=r){
            int mid = l+(r-l)/2;
            ans = min(nums[mid],ans);
            if(nums[mid]>=nums[l]&& nums[mid]>=nums[r]){
                l=mid+1;
            }
            else r = mid-1;

        }    
        return ans;    
    }
};
