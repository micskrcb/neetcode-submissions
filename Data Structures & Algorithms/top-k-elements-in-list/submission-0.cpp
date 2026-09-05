class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int> ans(k);
        set<pair<int,int>> s;
        unordered_map<int,int> mp;
        for(auto a: nums){
            mp[a]++;
        }
        for(auto pr: mp){
            s.insert({n-pr.second,pr.first});
            cout<<pr.first<<" "<<pr.second<<endl;
        }
        int i =0;
        for(auto a:s){
            if(i>=k)break;
            ans[i]=a.second;
            i++;
        }
        return ans;

        
    }
};
