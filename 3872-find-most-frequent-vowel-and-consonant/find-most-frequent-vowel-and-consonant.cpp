class Solution {
public:
    int maxFreqSum(string s) {
        set<char>st;
        for(int i=0;i<s.size();i++){
          if(s[i]=='a'||s[i]=='i'||s[i]=='e'||s[i]=='u'||s[i]=='o')  st.insert(s[i]);
        }
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int max1=0;
        int max2=0;
        for(auto it:m){
            if(st.find(it.first)!=st.end()){
                max1=max(max1,it.second);
            }
           else max2=max(max2,it.second);
        }
        cout<<max1<<max2;
        return max1+max2;
    }
};