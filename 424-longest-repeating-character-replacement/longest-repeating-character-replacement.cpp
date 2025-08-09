class Solution {
public:
    int characterReplacement(string s, int k) {
       int n=s.size();
       int l=0;
       //things to notice ==>> number of changes = length of window-maxfreq;
       int maxf=0;
       int maxlen=0;
       int hsh[26]={0};
       for(int r=0;r<n;r++){
           hsh[s[r]-'A']++;
          maxf=max(maxf,hsh[s[r]-'A']);
          int changes=(r-l+1)-maxf;
          if(changes<=k){
          maxlen=max(maxlen,r-l+1);
          }
          else {
            hsh[s[l]-'A']--;
            l++;
          }
       }
       return maxlen;
    }
};