class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int n=nums.size();
     int ans=INT_MIN;
     int sum=0;
     int start=0;
     int end=0;
     for(int i=0;i<n;i++){
        if(sum==0) start =i;
        sum+=nums[i];
         if(sum>ans){
            ans=sum;
            end=i;
         }
        if(sum<0) {
            sum=0; 
        }  
     }
        for(int i=start;i<=end;i++){
            cout<<nums[i]<<" ";
        }   
     
return ans;
    }
};