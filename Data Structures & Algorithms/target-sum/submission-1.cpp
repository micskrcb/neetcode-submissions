class Solution {
public:
    void helper(vector<int>& nums, int target,int idx,int sum,int&ans){
        if(idx==nums.size())ans+=(sum==target);
        else{
            helper(nums,target,idx+1,sum-nums[idx],ans);
            helper(nums,target,idx+1,sum+nums[idx],ans);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        helper(nums,target,0,0,ans);
        return ans;
        
    }
};
