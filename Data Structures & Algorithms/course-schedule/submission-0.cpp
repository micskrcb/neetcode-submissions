class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> in(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto a: prerequisites){
            in[a[0]]++;
            adj[a[1]].push_back(a[0]);
        }
        queue<int> q;
        for(int i =0;i<numCourses;i++){
            if(!in[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            for(auto a: adj[q.front()]){
                in[a]--;
                if(!in[a])q.push(a);
            }
            q.pop();

        }
        return ans.size()==numCourses;

        
    }
};
