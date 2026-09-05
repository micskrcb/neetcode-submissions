class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ans;
        for(int i =0;i<min(k,(int)nums.size());i++){
            s.insert(nums[i]);                        
        }
        ans.push_back(*s.rbegin());
        int l =0;
        int r =k;
        while(r<nums.size()){
            s.erase(s.find(nums[l])); // Erases only one instance via iterator
            s.insert(nums[r]);
            ans.push_back(*s.rbegin());
            l++;
            r++;
        }
        return ans;
        
    }
};
