class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>m;
        m[0]=1;
       //using prefix sum 
       int ans=0;
       int sum=0;
       for(int i=0;i<n;i++){
          sum+=nums[i];
         int remove=sum-k;
         ans+=m[remove];
         m[sum]+=1;
       }
       return ans;
    }
};