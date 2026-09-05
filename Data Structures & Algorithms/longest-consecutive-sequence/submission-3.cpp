class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto a:nums){
            s.insert(a);
        }
        int curr_streak;
        int ans=0;
        for(auto a:s){
            if(s.count(a-1))continue;
            curr_streak = 1;
            while(s.count(a+1)){
                curr_streak++;
                a++;
            }
            ans = max(ans,curr_streak);
                        
        }
        return ans;
        
    }
};
