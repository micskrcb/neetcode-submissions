class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int i =0;
        int n = nums.size();
        while(pq.size()<k && i<n){
            pq.push(nums[i]);
            i++;
        }
        while(i<n){
            if(nums[i]>pq.top()){
            pq.pop();
            pq.push(nums[i]);}
            i++;
        }
        
    }
    
    int add(int val) {
        if(pq.size()<K || val>pq.top()){
            if(pq.size()>=K)pq.pop();
            pq.push(val);}
            return pq.top();
        
        
    }
};
