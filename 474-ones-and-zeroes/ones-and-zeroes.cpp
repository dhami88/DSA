class Solution {
    int solve( vector<pair<int,int>>&count,int m,int n,int ind,vector<vector<vector<int>>>&dp){
        if(ind==count.size()||(m==0&&n==0)) return 0;
        int take=0;
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        if(count[ind].first<=m&&count[ind].second<=n){
           take=1+solve(count,m-count[ind].first,n-count[ind].second,ind+1,dp);
        }
        int nottake= solve(count,m,n,ind+1,dp);
        return dp[ind][m][n]=max(take,nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // similar to 0 1 knapsack 
        int len=strs.size();
        vector<pair<int,int>>count;
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(auto it:strs){
            int zeros=0,ones=0;
          for(int i=0;i<it.size();i++){
           if(it[i]=='0') zeros++;
           else ones++;
          }
          count.push_back({zeros,ones});
        }
       return solve(count,m,n,0,dp);
    }
};