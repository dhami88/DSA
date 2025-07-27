class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int left=0;
        int right=n-1;
       while(left<right){
        maxi=max(maxi,min(nums[left],nums[right])*(right-left));
        if(nums[left]<nums[right]){
            left++;
        }
        else right--;
       }
       return maxi;

    }
};