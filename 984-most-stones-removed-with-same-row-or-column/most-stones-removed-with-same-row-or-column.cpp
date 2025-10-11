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
    else {
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
  }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
             maxrow=max(maxrow,it[0]);
             maxcol=max(maxcol,it[1]);
        }
        //n-no of components
         set<int>st;
        disjointset ds(maxrow+maxcol+1);
        for(auto it:stones){
            int row=it[0];
            int col=maxrow+1+it[1];
            if(ds.findupar(row)!=ds.findupar(col)){
                ds.unionbysize(row,col);
                st.insert(row);
                st.insert(col);
            }
        }
        int nc=0;
        for(auto it:st){
            if(ds.findupar(it)==it){
                nc++;
            }
        }
        return n-nc;
    }
};