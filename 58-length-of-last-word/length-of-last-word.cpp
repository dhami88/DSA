class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int len=0;
        for(int i=0;i<n;i++){
          if(s[i]==' '){
                continue;
            }
            while(s[i]!=' '&&i<n){
                len++;
                i++;
            }
            break;
        }
        return len;
    }
};