class disjointset{
    public:
    vector<int>parent,size;
    public:
    disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findupar(int node){
        if(node==parent[node]) return node;
        else return parent[node]=findupar(parent[node]);

    }
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
                    }
         else{
          parent[ulp_v]=ulp_u;
           size[ulp_u]+=size[ulp_v];
                    }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //total number of components-1
        disjointset ds(n);
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            int ulp_u=ds.findupar(u);
            int ulp_v=ds.findupar(v);
            if(ulp_u==ulp_v) continue;
            else ds.unionbysize(u,v);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        if(connections.size()<n-1) return -1;
        return cnt-1;
    }
};