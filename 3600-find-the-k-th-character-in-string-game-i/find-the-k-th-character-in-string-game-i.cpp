class Solution {
public:
    char kthCharacter(int k) {
       string s ="a";
        while(s.length()<k){
            int size=s.length();
      for(int i=0;i<size;i++){
         char c= 'a'+((s[i]-'a'+1)%26);
         s+=c;
      } 
        }  
        return s[k-1]; 
    }
};