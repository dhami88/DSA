class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int l=0;
     int r=0;
     int n=s.size();
     vector<int>hsh(256,-1);
     int len=0;
     while(r<n){
        if(hsh[s[r]]>=l){
            l=hsh[s[r]]+1;
        }
       hsh[s[r]]=r;
       len=max(len,r-l+1);
       r++;
     }
     return len;
    }
};