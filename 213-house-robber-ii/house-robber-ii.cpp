class Solution {
    int f(vector<int>&temp){
        int prev=temp[0];
        int prev2=0;
        for(int i=1;i<temp.size();i++){
            int pick=temp[i];
            if(i>1) pick+=prev2;
            int notpick=prev;
            int cur=max(pick,notpick);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        //catch : first and last cannot be in the answer simultaneously
        if(nums.size()==1) return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1),f(temp2));
    }
};