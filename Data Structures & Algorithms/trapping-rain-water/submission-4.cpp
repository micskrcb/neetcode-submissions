class Solution {
public:
    int trap(vector<int>& height) {
        int maxl = 0;
        int maxr = 0;

        int l =0;
        int r = height.size()-1;

        int ans =0;

        while(l<r){
            maxl=max(maxl,height[l]);
            maxr=max(maxr,height[r]);
            if(height[l]>height[r]){
                ans+=max(0,min(maxl,maxr)-height[r]);
                r--;
            }
            else{
                 ans+=max(0,min(maxl,maxr)-height[l]);
                l++;
            }
        }
        return ans;
        
    }
};
