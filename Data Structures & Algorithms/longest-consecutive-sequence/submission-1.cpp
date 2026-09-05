class Solution {
public:
    map<int,int> parent;
    map<int,int> size;
    int find(int i){
        if(parent.find(i)==parent.end())return INT_MIN;
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void join(int i, int j){        
        i = find(i);
        j = find(j);
        if(i==INT_MIN || j==INT_MIN) return;
        if(i==j)return;
        if(size[i]>size[j]) swap(i,j);
        parent[i]=j;
        size[j]+=size[i];
    }
    
    int longestConsecutive(vector<int>& nums) {        
        int i = nums.size();
        for(int i =0;i<nums.size();i++){
            parent[nums[i]]=nums[i];
            size[nums[i]]=1;                        
        }
        int ans = 0;
        for(auto a:nums){
            join(a,a-1);
            join(a,a+1);
            ans=max(ans,size[find(a)]);
        }  
        return ans;      
    }
};
