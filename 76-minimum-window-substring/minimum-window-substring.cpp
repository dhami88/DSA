class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int ind=-1;
        int len=1e9;
        int l=0;
        int cnt=0;
        int hsh[256]={0};
        for(int i=0;i<m;i++){
            hsh[t[i]]++;
        }
        for(int r=0;r<n;r++){
            if((hsh[s[r]])>0) cnt++;
            hsh[s[r]]--;
            while(cnt==m){
                if(r-l+1<len){
                    len=r-l+1;
                    ind=l;
                }
                hsh[s[l]] ++;
                if((hsh[s[l]])>0) cnt--;
                l++;
            }
        }
        if(ind==-1) return "";
        else return s.substr(ind,len);

    }
};