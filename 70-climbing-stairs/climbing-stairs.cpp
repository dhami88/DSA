class Solution {
    int f(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] =f(n-1,dp)+f(n-2,dp);
    }
public:
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
      int prev2 =1;
      int prev =1;
      // return f(n,dp);
      for(int i=2;i<=n;i++){
        int cur=prev+prev2;
        prev2=prev;
        prev=cur;
      }
      return prev;
    }
};