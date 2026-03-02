class Solution {
public:
    string trimTrailingVowels(string s) {
        int i= s.size()-1;
        while(i>=0){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                i--;
            }
            else break;
        }
        string ans;
        for(int j=0;j<=i;j++){
            ans.push_back(s[j]);
        }
        return ans;
    }
};