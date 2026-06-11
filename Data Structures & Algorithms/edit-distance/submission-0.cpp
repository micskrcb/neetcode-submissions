class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int j = 0; j <= m; j++) {
            curr[j] = j;
            cout<<curr[j]<<" ";
        }
        cout<<endl;

        for (int i = 1; i <= n; i++) {
            fill(next.begin(), next.end(), 0);
            for(int j=0;j<=m;j++){
                if(j==0)next[j]=i;
                else{
                    if(word1[i-1]==word2[j-1])next[j]=curr[j-1];
                    else{
                        next[j]=1+min(next[j-1],curr[j]);
                        next[j]=min(next[j],1+curr[j-1]);
                    }
                }
                cout<<next[j]<<" ";
            }
            cout<<"\n";
            curr=next;
        }

        return curr[m];
    }
};
