class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //doing using prefix max and suffix max
        vector<int>premax(n);
        vector<int>sufmax(n);
        premax[0]=height[0];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],height[i]);
        }
        sufmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufmax[i]=max(sufmax[i+1],height[i]);

        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(premax[i],sufmax[i]))-height[i];
        }
        return ans;
    }
};