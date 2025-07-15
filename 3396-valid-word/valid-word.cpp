class Solution {
public:
    bool isValid(string word) {
      if(word.length()<3) return false;
       int n=word.size();
       string vowels="aeiouAEIOU";
       int v=0;
       int c=0;
       for(int i=0;i<n;i++){
        if(isalpha(word[i])){
            if(vowels.find(word[i])!=string::npos){
                v++;
            }
            else c++;
        }
        else if(!isdigit(word[i])){
            return false;
        }
       }
       return (v>=1)&&(c>=1);
    }
};