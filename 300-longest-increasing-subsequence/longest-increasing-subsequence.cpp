class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //dp[i] represents the length of lis till index i
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int prev=i-1;prev>=0;prev--){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }

        } 
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};