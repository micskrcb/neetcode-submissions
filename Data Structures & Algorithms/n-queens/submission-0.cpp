class Solution {
public:
    bool helper(int i,int n,vector<bool> row,vector<string>& grid,vector<vector<string>>& ans){
        cout<<"i: "<<i<<endl;
        if(i==n){
            ans.push_back(grid);
        }
        for(int idx = 0;idx<n;idx++){
            if(row[idx]==false){
                int x = i;
                int y =idx;
                while(x>=0 && y>=0 && grid[x][y]=='.'){
                    x--;
                    y--;
                }
                if(x<0||y<0){
                    x = i;
                    y =idx;
                    while(x>=0 && y<n && grid[x][y]=='.'){
                    x--;
                    y++;
                }
                if(x<0||y>=n){
                    grid[i][idx]='Q';
                    row[idx]=true;
                    if(helper(i+1,n,row,grid,ans)){
                        return true;
                    }
                    grid[i][idx]='.';
                    row[idx]=false;
                }
                }
            }
        }
        return false;

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n,string(n,'.'));
        vector<vector<string>> ans;
        vector<bool> row(n,false);
        helper(0,n,row,grid,ans);  
        return ans;     
    }
};
