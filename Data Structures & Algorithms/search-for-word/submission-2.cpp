class Solution {
public:
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& vis,string s, string word,int i,int j){
        if(s.size()>word.size()) return false;
        // cout<<i<<" "<<j<<endl;
        //cout<<s<<endl;
        vector<int> dx ={0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        int n = board.size();
        int m = board[0].size();
        bool temp = false;
        vis[i][j]=1;
        if(word == s+board[i][j]) return true;
       
        for(int p =0;p<4;p++){
            int x = dx[p]+i;
            int y = dy[p]+j;
             //cout<<"bye"<<endl;
            if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0){
                // cout<<"bye"<<endl;
                temp = temp || dfs(board,vis,s+board[i][j],word,x,y);
                if(temp) return temp;
            }
        }
        vis[i][j]=0;
        return temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                vector<vector<int>> vis(n,vector<int>(m,0));
                string s ="";
                if(dfs(board,vis,s,word,i,j))
                return true;
            }
        }
        return false;        
    }
};
