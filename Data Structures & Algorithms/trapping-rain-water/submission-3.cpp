class Solution {
public:
    int trap(vector<int>& height) {
        //the water at any pos p is max(0,min(max h on left,max h on right)-hp);
        //precompute max pos till i from l to r;
        int n = height.size();
        int ans =0;

        vector<int> max_h(n);
        int mx = 0;
        for(int i =0;i<n;i++){
            max_h[i]=mx;
            mx = max(mx,height[i]);
        }
        mx=0;
        for(int i =n-1;i>=0;i--){
            ans+=max(0,min(max_h[i],mx)-height[i]);
            mx=max(mx,height[i]);
        }
        return ans;
    }
};
