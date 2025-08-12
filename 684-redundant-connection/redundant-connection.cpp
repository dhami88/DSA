class disjointset{
    vector<int>parent,size;
    public:
    disjointset (int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findupar(int node){
        if(parent[node]==node) return node;
        else return parent[node]=findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return ;
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //kruskals algorithm for mst
        int n=edges.size();
        vector<int>ans;
       disjointset ds(n);
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            if(ds.findupar(a)!=ds.findupar(b)) {
                ds.unionbysize(a,b);
            }
            else {
                ans.push_back(a);
                ans.push_back(b);
            }
        }
        return ans;
    }
};