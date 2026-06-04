class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i =0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int cnt = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto[x,y]=q.front();
                        //cout<<x<<y<<"\n";
                        cnt++;
                        grid[x][y]=0;
                        q.pop();
                        int dx[]={-1,1,0,0};
                        int dy[]={0,0,-1,1};
                        for(int p =0;p<4;p++){
                            int nx = x+dx[p];
                            int ny = y+dy[p];
                            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()){
                                if(grid[nx][ny]==1){
                                    q.push({nx,ny});
                                    grid[nx][ny]=0;
                                }
                            }
                        }
                    }
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
        
    }
};
