class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int target = -1* nums[i];
            int l =i+1;
            int r = n-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    //cout<<"hi"<<endl;
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(nums[l]==nums[l-1])l++;
                    while(nums[r]==nums[r+1])r--;
                }
                else if(nums[l]+nums[r]>target)r--;
                else l++;
            }

        } 
        return ans;       
    }
};
