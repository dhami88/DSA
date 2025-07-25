class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int n=numbers.size();
        int n=nums.size();
         //O(1) space
         int i=0;
         int j=n-1;
         while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==target) return {i+1,j+1};
            else if(sum<target) i++;
            else j--;
         }
         return {-1,-1};
    }
};