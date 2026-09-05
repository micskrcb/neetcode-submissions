class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r= heights.size()-1;
        int ans = 0;
        while(l<r){
            int dis = r-l;
            ans= max(ans,dis*min(heights[l],heights[r]));
            if(heights[l]>heights[r])r--;
            else l++;
        }
        return ans;
        
    }
};
