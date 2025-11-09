class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i] indicates the length of the lis ending at index i
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int ind=0;ind<i;ind++){
               if(nums[i]>nums[ind]) dp[i]=max(dp[i],1+dp[ind]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};