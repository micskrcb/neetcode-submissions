class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,int> mp;
        for(auto s: strs){
            vector<int> vec(26);
            for(auto a : s){
                vec[a-'a']++;
            }
            if(mp.find(vec)==mp.end()){mp[vec]=ans.size(); ans.push_back({});}
            ans[mp[vec]].push_back(s);
        }
        
        return ans;        
    }
};
