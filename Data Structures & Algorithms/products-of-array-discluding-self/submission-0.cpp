class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n  = nums.size();
        vector<int> ans(n,1);
        vector<int> pre(n,1);
        for(int i =n-2;i>=0;i--){
            pre[i]=pre[i+1]*nums[i+1];
        }
        for(auto a : pre){
            cout<<a<<" ";
        }
        cout<<endl;
int temp = 1; 
         for(int i =1;i<n;i++){
            pre[i] *= temp*nums[i-1];
            temp *= nums[i-1];
        }
        return pre;


    }
};
