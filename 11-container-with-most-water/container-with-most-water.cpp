class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<=right){
            ans=max(ans,min(nums[left],nums[right])*(right-left));
            if(nums[left]<nums[right]){
                left++;
            }
            else right--;
        }
        return ans;
    }
};