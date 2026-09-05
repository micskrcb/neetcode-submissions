class Solution {
public:
    bool canJump(vector<int>& nums) {

        int i =0;
        while(i<nums.size()){
            int x = nums[i];
            if(x==0)break;
            
            int mx = i+1;
            if(mx >= nums.size()) break;
            for(int j = 1;j<=x;j++){
                if(i+j+nums[i+j]>mx+nums[mx])mx=i+j;
            }
            i=mx;
        }
        return i>=nums.size()-1;
        
    }
};
