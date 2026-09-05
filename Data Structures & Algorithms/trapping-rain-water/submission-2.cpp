class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        int lvlwtr = 0;
        int prev = -1;
        int mx = height[0];
        for(int i =0;i<n;i++){     
            mx = max(mx,height[i]);       
            if(height[i]>0){
                lvlwtr += (i-prev-1)*(prev!=-1);
                prev = i;
            }
            height[i]--;
        }
        ans+=lvlwtr;
        //cout<<lvlwtr<<endl;
        while(mx--){
            prev = -1;
            lvlwtr = 0;
            for(int i =0;i<n;i++){            
            if(height[i]>0){
                //cout<<"i: "<<i<<" lw: "<<i-prev-1<<endl;
                lvlwtr += (i-prev-1)*(prev!=-1);
                prev = i;
            }
            height[i]--;
        }
        ans+=lvlwtr;
        cout<<lvlwtr<<endl;
        }
        return ans;
    }
};
