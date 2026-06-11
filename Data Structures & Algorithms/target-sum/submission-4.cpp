class Solution {
   public:
    void helper(vector<int>& nums, int target, int idx, int sum, int& ans) {
        if (idx == nums.size())
            ans += (sum == target);
        else {
            helper(nums, target, idx + 1, sum - nums[idx], ans);
            helper(nums, target, idx + 1, sum + nums[idx], ans);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // int ans=0;
        // helper(nums,target,0,0,ans);
        // return ans;
        int n = nums.size();
        int s =0;
        for(auto a:nums)s+=a;
       vector<int> curr (2 * (s + 3), 0);
       vector<int> next (2 * (s + 3), 0);
       vector<int> empty (2 * (s + 3), 0);
        int offset = s;
        curr[0 + offset] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < curr.size(); j++) {
                if (curr[j] != 0) {
                    if (j - nums[i] >= 0) next[j - nums[i]] += curr[j];
                    if (j + nums[i] < curr.size()) next[j + nums[i]] += curr[j];
                }
            }
           curr=next;
           next = empty;
        }
        return curr[target+offset];
    }
}

;
