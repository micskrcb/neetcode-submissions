class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast =0;
        int slow =0;
        slow = nums[slow];
        fast =nums[nums[fast]];
        //if(nums[fast]=nums[slow])
        while(slow!=fast){
            slow=nums[slow];
            fast =nums[nums[fast]];
        }
        slow =0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;

    }
};
