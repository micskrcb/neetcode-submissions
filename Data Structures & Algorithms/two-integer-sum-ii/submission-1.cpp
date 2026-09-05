class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int l =0;
        int r = numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            }
            else if(numbers[l]+numbers[r]>target){
                r--;
            }
            else l++;
        }
        return ans;
        
    }
};
