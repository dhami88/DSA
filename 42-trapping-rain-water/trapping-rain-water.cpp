class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int>premax(n,0);
        vector<int>sufmax(n,0);
        premax[0]=height[0];
        sufmax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            premax[i]=max(height[i],premax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            sufmax[i]=max(height[i],sufmax[i+1]);
        }
        for(int i=0;i<n;i++){
            ans+=min(premax[i],sufmax[i])-height[i];
        }
        return ans;
    }
};