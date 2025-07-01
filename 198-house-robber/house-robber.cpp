class Solution {
    int f(int ind,vector<int>& nums,vector<int>&dp){
        if(ind==0) return nums[0];
         if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
      int pick=nums[ind]+f(ind-2,nums,dp);
        int notpick=f(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n+1,0);
      // return f(n-1,nums,dp);
      dp[0]=nums[0];
      for(int ind=1;ind<n;ind++){
        int pick=nums[ind];
        if(ind>1) pick+=dp[ind-2];
        int notpick=dp[ind-1];
       dp[ind]=max(pick,notpick);
      }
      return dp[n-1];
    }
};