class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto a : nums){
            if(s.count(a)) return !false;
            s.insert(a);
        }  
        return !true;              
    }
};