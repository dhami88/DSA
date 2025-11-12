class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        // min length subarray with gcd=1;
        //gcd(x,0)=x;
        int ones=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) ones++;
        }
        if(ones>0) return n-ones; 
        int len=n+1;
        for(int i=0;i<n;i++){
            int g=0;
            for(int j=i;j<n;j++){
                g=gcd(g,nums[j]);
                if(g==1) len=min(len,j-i+1);
            }
        }
        if(len==n+1) return -1;
        else return len+n-2;;
    }
};