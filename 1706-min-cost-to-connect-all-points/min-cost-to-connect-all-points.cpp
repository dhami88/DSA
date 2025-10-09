class disjointset{
    vector<int>parent,size;
    public:
    disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findupar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findupar(parent[node]);
    }
    
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]<size[ulp_v]){
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int m=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({m,{i,j}});
                adj.push_back({m,{j,i}});
            }
        }
        //now finding the mst
        sort(adj.begin(),adj.end());
        vector<int>vis(n,0);
       disjointset ds(n);
       int ans=0;
       for(auto it:adj){
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.findupar(u)!=ds.findupar(v)){
                ans+=wt;
                ds.unionbysize(u,v);
            }

       }
       return ans;
    }
};