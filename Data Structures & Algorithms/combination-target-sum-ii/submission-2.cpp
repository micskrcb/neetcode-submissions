class Solution {
public:
void helper(int i,int s,vector<int>&candidates,int target,vector<int>& temp,vector<vector<int>>& ans){
              if(s==target){
                ans.push_back(temp);
                return;
              }
              if(i>=candidates.size()|| s>target){
                return;
              }
              temp.push_back(candidates[i]);
              helper(i+1,s+candidates[i],candidates, target, temp,ans);
              temp.pop_back();
              i++;
              while(i<candidates.size() && candidates[i]==candidates[i-1]){
                i++;
              }
              helper(i,s,candidates, target, temp,ans);
              //cout<<i<<" "<<s<<endl;              

        }
        
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        
        helper(0,0,candidates, target, temp,ans);

        return ans;
        
    }
};
