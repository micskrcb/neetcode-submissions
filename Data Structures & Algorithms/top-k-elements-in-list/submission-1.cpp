class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(100000);
        map<int,int> cnt;
        for(auto a:nums){
            cnt[a]++;
        }
        for(auto a:cnt){
            bucket[a.second].push_back(a.first);
        }
        vector<int> ans;
        for(int i = bucket.size()-1;i>=0;i--){
            if(bucket[i].size()!=0){
                for(auto a:bucket[i]){
                    ans.push_back(a);
                    if(ans.size()==k) return ans;
                }
            }            
        }

    }
};
