class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     int n=nums.size();
     long long ans=0;
     int cntsub=0;
     for(int i=0;i<n;i++){
        if(nums[i]==0){
            cntsub++;
        }
        else cntsub=0;
        ans+=cntsub;
     }   
     return ans;
    }
};