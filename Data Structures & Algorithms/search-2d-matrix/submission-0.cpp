class Solution {
public:
   

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = m*n-1;

        while(l<=r){
            int mid = l-(l-r)/2;
            int x = mid/m;
            int y = mid%m;
            if(matrix[x][y]==target) return true;
            if(matrix[x][y]<target)l=mid+1;
            else r= mid-1;
        }
        return false;
                
    }
};
