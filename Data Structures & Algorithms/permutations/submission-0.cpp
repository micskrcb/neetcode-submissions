class Solution {
public:
    void helper(vector<vector<int>>& ans,int idx,vector<int>& temp){
        if(idx==temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = idx;i<temp.size();i++){
            swap(temp[i],temp[idx]);
            helper(ans,idx+1,temp);
            swap(temp[i],temp[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans;
        helper(ans,0,nums);
        return ans;
    }
};
