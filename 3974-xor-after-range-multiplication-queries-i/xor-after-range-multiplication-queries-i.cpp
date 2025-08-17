class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        long long int MOD=1e9+7;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            for(int i=l;i<=r;i+=k){
                nums[i]=(1LL*nums[i]*v)%MOD;
            }
        }
        int ans=nums[0];
        for(int i=1;i<n;i++) {
           ans=ans^nums[i];
        }
       return ans;
    }
};