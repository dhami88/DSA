class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
      //using the most optimal way
      int l=0;
      int r=n-1;
      int lmax=0,rmax=0,ans=0;
      while(l<r){
        if(arr[l]<=arr[r]){
            if(arr[l]<lmax){
                ans+=lmax-arr[l];
            }
           else lmax=arr[l];
            l++;
        }
        else{
            if(arr[r]<rmax){
                ans+=rmax-arr[r];
            }
           else rmax=arr[r];
            r--;
        }
      }
      return ans;
    }
};