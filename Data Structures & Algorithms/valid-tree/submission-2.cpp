class Solution {
public:
    vector<int> size;
    vector<int> parent;

    int find(int u){
        if(parent[u]==u) return u;
        else return parent[u]=find(parent[u]);
    }

    bool join(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return true;
        if(size[u]>size[v])swap(u,v);
        size[v]+=size[u];
        parent[u]=v;
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        size.resize(n,1);
        parent.resize(n,0);
        for(int i =1;i<n;i++){
            parent[i]=i;
        }
        for(auto a:edges){
            if(join(a[0],a[1]))return false;
        }
        int a = parent[0];
        for(auto b: parent){
            if(find(b)!=find(a)) return false;
        }
        return true;

    }
};
