class Solution {
    int f(int ind,int prev,vector<int>& nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nottake=f(ind+1,prev,nums,dp);
        int take=INT_MIN;
        if(prev==-1||nums[ind]>nums[prev]){
            take=1+f(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
      //  vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      vector<int>front(n+1,0),cur(n+1,0);
        //return f(0,-1,nums,dp);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int nottake=front[prev+1];
            int take=INT_MIN;
             if(prev==-1||nums[ind]>nums[prev]){
            take=1+front[ind+1];
        }
         cur[prev+1]=max(take,nottake);
            }
             front=cur;
        }
      
        return front[0];
    }
};