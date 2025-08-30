class disjointset{
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
    if (parent[node]==node) return node;
    else return parent[node]=findupar(parent[node]);
   }
   void unionbysize(int u,int v){
    int ulp_u=findupar(u);
    int ulp_v=findupar(v);
    if(ulp_u==ulp_v) return;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Using disjoint set union
        int n=isConnected.size();
        disjointset ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j){
                    ds.unionbysize(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findupar(i)==i) cnt++;
        }
        return cnt;
    }
};