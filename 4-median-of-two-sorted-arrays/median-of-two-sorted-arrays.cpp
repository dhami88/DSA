class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
      int n=a.size();
      int m=b.size();
      int i=0,j=0;
      vector<int>ans;
      while(i<n&&j<m){
        if(a[i]<=b[j]){
            ans.push_back(a[i]);
            i++;
        }
        else {
            ans.push_back(b[j]);
        j++;
        }
      }
    while(i<n){
        ans.push_back(a[i]);
        i++;
      }
     while(j<m){
        ans.push_back(b[j]);
        j++;
      }
      int x=ans.size();
      if(x%2==0) return (double)(ans[(x/2)-1]+ans[(x/2)])/2;
     else  return ans[x/2];
    }
};